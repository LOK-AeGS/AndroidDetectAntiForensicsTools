
#ifndef __LINUX_BIO_H
#define __LINUX_BIO_H

#include <linux/highmem.h>
#include <linux/mempool.h>
#include <linux/ioprio.h>
#include <linux/bug.h>
#include <linux/bio-crypt-ctx.h>
#include <linux/android_kabi.h>

#ifdef CONFIG_BLOCK

#include <asm/io.h>


#include <linux/blk_types.h>

#define BIO_DEBUG

#ifdef BIO_DEBUG
#define BIO_BUG_ON	BUG_ON
#else
#define BIO_BUG_ON
#endif

#ifdef CONFIG_THP_SWAP
#if HPAGE_PMD_NR > 256
#define BIO_MAX_PAGES		HPAGE_PMD_NR
#else
#define BIO_MAX_PAGES		256
#endif
#else
#define BIO_MAX_PAGES		256
#endif

#define bio_prio(bio)			(bio)->bi_ioprio
#define bio_set_prio(bio, prio)		((bio)->bi_ioprio = prio)

#define bio_iter_iovec(bio, iter)				\
	bvec_iter_bvec((bio)->bi_io_vec, (iter))

#define bio_iter_page(bio, iter)				\
	bvec_iter_page((bio)->bi_io_vec, (iter))
#define bio_iter_len(bio, iter)					\
	bvec_iter_len((bio)->bi_io_vec, (iter))
#define bio_iter_offset(bio, iter)				\
	bvec_iter_offset((bio)->bi_io_vec, (iter))

#define bio_page(bio)		bio_iter_page((bio), (bio)->bi_iter)
#define bio_offset(bio)		bio_iter_offset((bio), (bio)->bi_iter)
#define bio_iovec(bio)		bio_iter_iovec((bio), (bio)->bi_iter)

#define bio_multiple_segments(bio)				\
	((bio)->bi_iter.bi_size != bio_iovec(bio).bv_len)

#define bvec_iter_sectors(iter)	((iter).bi_size >> 9)
#define bvec_iter_end_sector(iter) ((iter).bi_sector + bvec_iter_sectors((iter)))

#define bio_sectors(bio)	bvec_iter_sectors((bio)->bi_iter)
#define bio_end_sector(bio)	bvec_iter_end_sector((bio)->bi_iter)


#define bio_data_dir(bio) \
	(op_is_write(bio_op(bio)) ? WRITE : READ)


static inline bool bio_has_data(struct bio *bio)
{
	if (bio &&
	    bio->bi_iter.bi_size &&
	    bio_op(bio) != REQ_OP_DISCARD &&
	    bio_op(bio) != REQ_OP_SECURE_ERASE &&
	    bio_op(bio) != REQ_OP_WRITE_ZEROES)
		return true;

	return false;
}

static inline bool bio_no_advance_iter(struct bio *bio)
{
	return bio_op(bio) == REQ_OP_DISCARD ||
	       bio_op(bio) == REQ_OP_SECURE_ERASE ||
	       bio_op(bio) == REQ_OP_WRITE_SAME ||
	       bio_op(bio) == REQ_OP_WRITE_ZEROES;
}

static inline bool bio_mergeable(struct bio *bio)
{
	if (bio->bi_opf & REQ_NOMERGE_FLAGS)
		return false;

	return true;
}

static inline unsigned int bio_cur_bytes(struct bio *bio)
{
	if (bio_has_data(bio))
		return bio_iovec(bio).bv_len;
	else 
		return bio->bi_iter.bi_size;
}

static inline void *bio_data(struct bio *bio)
{
	if (bio_has_data(bio))
		return page_address(bio_page(bio)) + bio_offset(bio);

	return NULL;
}

static inline bool bio_full(struct bio *bio)
{
	return bio->bi_vcnt >= bio->bi_max_vecs;
}


#define bvec_to_phys(bv)	(page_to_phys((bv)->bv_page) + (unsigned long) (bv)->bv_offset)




#define __BIOVEC_PHYS_MERGEABLE(vec1, vec2)	\
	((bvec_to_phys((vec1)) + (vec1)->bv_len) == bvec_to_phys((vec2)))


#ifndef BIOVEC_PHYS_MERGEABLE
#define BIOVEC_PHYS_MERGEABLE(vec1, vec2)	\
	__BIOVEC_PHYS_MERGEABLE(vec1, vec2)
#endif

#define __BIO_SEG_BOUNDARY(addr1, addr2, mask) \
	(((addr1) | (mask)) == (((addr2) - 1) | (mask)))
#define BIOVEC_SEG_BOUNDARY(q, b1, b2) \
	__BIO_SEG_BOUNDARY(bvec_to_phys((b1)), bvec_to_phys((b2)) + (b2)->bv_len, queue_segment_boundary((q)))


#define bio_for_each_segment_all(bvl, bio, i)				\
	for (i = 0, bvl = (bio)->bi_io_vec; i < (bio)->bi_vcnt; i++, bvl++)

static inline void bio_advance_iter(struct bio *bio, struct bvec_iter *iter,
				    unsigned bytes)
{
	iter->bi_sector += bytes >> 9;

	if (bio_no_advance_iter(bio)) {
		iter->bi_size -= bytes;
		iter->bi_done += bytes;
	} else {
		bvec_iter_advance(bio->bi_io_vec, iter, bytes);
		
	}
}

static inline bool bio_rewind_iter(struct bio *bio, struct bvec_iter *iter,
		unsigned int bytes)
{
	iter->bi_sector -= bytes >> 9;

	if (bio_no_advance_iter(bio)) {
		iter->bi_size += bytes;
		iter->bi_done -= bytes;
		return true;
	}

	return bvec_iter_rewind(bio->bi_io_vec, iter, bytes);
}

#define __bio_for_each_segment(bvl, bio, iter, start)			\
	for (iter = (start);						\
	     (iter).bi_size &&						\
		((bvl = bio_iter_iovec((bio), (iter))), 1);		\
	     bio_advance_iter((bio), &(iter), (bvl).bv_len))

#define bio_for_each_segment(bvl, bio, iter)				\
	__bio_for_each_segment(bvl, bio, iter, (bio)->bi_iter)

#define bio_iter_last(bvec, iter) ((iter).bi_size == (bvec).bv_len)

static inline unsigned bio_segments(struct bio *bio)
{
	unsigned segs = 0;
	struct bio_vec bv;
	struct bvec_iter iter;

	

	switch (bio_op(bio)) {
	case REQ_OP_DISCARD:
	case REQ_OP_SECURE_ERASE:
	case REQ_OP_WRITE_ZEROES:
		return 0;
	case REQ_OP_WRITE_SAME:
		return 1;
	default:
		break;
	}

	bio_for_each_segment(bv, bio, iter)
		segs++;

	return segs;
}


static inline void bio_get(struct bio *bio)
{
	bio->bi_flags |= (1 << BIO_REFFED);
	smp_mb__before_atomic();
	atomic_inc(&bio->__bi_cnt);
}

static inline void bio_cnt_set(struct bio *bio, unsigned int count)
{
	if (count != 1) {
		bio->bi_flags |= (1 << BIO_REFFED);
		smp_mb();
	}
	atomic_set(&bio->__bi_cnt, count);
}

static inline bool bio_flagged(struct bio *bio, unsigned int bit)
{
	return (bio->bi_flags & (1U << bit)) != 0;
}

static inline void bio_set_flag(struct bio *bio, unsigned int bit)
{
	bio->bi_flags |= (1U << bit);
}

static inline void bio_clear_flag(struct bio *bio, unsigned int bit)
{
	bio->bi_flags &= ~(1U << bit);
}

static inline void bio_get_first_bvec(struct bio *bio, struct bio_vec *bv)
{
	*bv = bio_iovec(bio);
}

static inline void bio_get_last_bvec(struct bio *bio, struct bio_vec *bv)
{
	struct bvec_iter iter = bio->bi_iter;
	int idx;

	if (unlikely(!bio_multiple_segments(bio))) {
		*bv = bio_iovec(bio);
		return;
	}

	bio_advance_iter(bio, &iter, iter.bi_size);

	if (!iter.bi_bvec_done)
		idx = iter.bi_idx - 1;
	else	
		idx = iter.bi_idx;

	*bv = bio->bi_io_vec[idx];

	
	if (iter.bi_bvec_done)
		bv->bv_len = iter.bi_bvec_done;
}

static inline unsigned bio_pages_all(struct bio *bio)
{
	WARN_ON_ONCE(bio_flagged(bio, BIO_CLONED));
	return bio->bi_vcnt;
}

static inline struct bio_vec *bio_first_bvec_all(struct bio *bio)
{
	WARN_ON_ONCE(bio_flagged(bio, BIO_CLONED));
	return bio->bi_io_vec;
}

static inline struct page *bio_first_page_all(struct bio *bio)
{
	return bio_first_bvec_all(bio)->bv_page;
}

static inline struct bio_vec *bio_last_bvec_all(struct bio *bio)
{
	WARN_ON_ONCE(bio_flagged(bio, BIO_CLONED));
	return &bio->bi_io_vec[bio->bi_vcnt - 1];
}

enum bip_flags {
	BIP_BLOCK_INTEGRITY	= 1 << 0, 
	BIP_MAPPED_INTEGRITY	= 1 << 1, 
	BIP_CTRL_NOCHECK	= 1 << 2, 
	BIP_DISK_NOCHECK	= 1 << 3, 
	BIP_IP_CHECKSUM		= 1 << 4, 
};


struct bio_integrity_payload {
	struct bio		*bip_bio;	

	struct bvec_iter	bip_iter;

	unsigned short		bip_slab;	
	unsigned short		bip_vcnt;	
	unsigned short		bip_max_vcnt;	
	unsigned short		bip_flags;	

	struct work_struct	bip_work;	

	struct bio_vec		*bip_vec;

	ANDROID_KABI_RESERVE(1);
	ANDROID_KABI_RESERVE(2);

	struct bio_vec		bip_inline_vecs[0];
};

#if defined(CONFIG_BLK_DEV_INTEGRITY)

static inline struct bio_integrity_payload *bio_integrity(struct bio *bio)
{
	if (bio->bi_opf & REQ_INTEGRITY)
		return bio->bi_integrity;

	return NULL;
}

static inline bool bio_integrity_flagged(struct bio *bio, enum bip_flags flag)
{
	struct bio_integrity_payload *bip = bio_integrity(bio);

	if (bip)
		return bip->bip_flags & flag;

	return false;
}

static inline sector_t bip_get_seed(struct bio_integrity_payload *bip)
{
	return bip->bip_iter.bi_sector;
}

static inline void bip_set_seed(struct bio_integrity_payload *bip,
				sector_t seed)
{
	bip->bip_iter.bi_sector = seed;
}

#endif 

extern void bio_trim(struct bio *bio, int offset, int size);
extern struct bio *bio_split(struct bio *bio, int sectors,
			     gfp_t gfp, struct bio_set *bs);


static inline struct bio *bio_next_split(struct bio *bio, int sectors,
					 gfp_t gfp, struct bio_set *bs)
{
	if (sectors >= bio_sectors(bio))
		return bio;

	return bio_split(bio, sectors, gfp, bs);
}

enum {
	BIOSET_NEED_BVECS = BIT(0),
	BIOSET_NEED_RESCUER = BIT(1),
};
extern int bioset_init(struct bio_set *, unsigned int, unsigned int, int flags);
extern void bioset_exit(struct bio_set *);
extern int biovec_init_pool(mempool_t *pool, int pool_entries);
extern int bioset_init_from_src(struct bio_set *bs, struct bio_set *src);

extern struct bio *bio_alloc_bioset(gfp_t, unsigned int, struct bio_set *);
extern void bio_put(struct bio *);

extern void bio_clone_crypt_key(struct bio *dst, const struct bio *src);
extern void __bio_clone_fast(struct bio *, struct bio *);
extern struct bio *bio_clone_fast(struct bio *, gfp_t, struct bio_set *);

extern struct bio_set fs_bio_set;

static inline struct bio *bio_alloc(gfp_t gfp_mask, unsigned int nr_iovecs)
{
	return bio_alloc_bioset(gfp_mask, nr_iovecs, &fs_bio_set);
}

static inline struct bio *bio_kmalloc(gfp_t gfp_mask, unsigned int nr_iovecs)
{
	return bio_alloc_bioset(gfp_mask, nr_iovecs, NULL);
}

extern blk_qc_t submit_bio(struct bio *);

extern void bio_endio(struct bio *);

static inline void bio_io_error(struct bio *bio)
{
	bio->bi_status = BLK_STS_IOERR;
	bio_endio(bio);
}

static inline void bio_wouldblock_error(struct bio *bio)
{
	bio->bi_status = BLK_STS_AGAIN;
	bio_endio(bio);
}

struct request_queue;
extern int bio_phys_segments(struct request_queue *, struct bio *);

extern int submit_bio_wait(struct bio *bio);
extern void bio_advance(struct bio *, unsigned);

extern void bio_init(struct bio *bio, struct bio_vec *table,
		     unsigned short max_vecs);
extern void bio_uninit(struct bio *);
extern void bio_reset(struct bio *);
void bio_chain(struct bio *, struct bio *);

extern int bio_add_page(struct bio *, struct page *, unsigned int,unsigned int);
extern int bio_add_pc_page(struct request_queue *, struct bio *, struct page *,
			   unsigned int, unsigned int);
bool __bio_try_merge_page(struct bio *bio, struct page *page,
		unsigned int len, unsigned int off);
void __bio_add_page(struct bio *bio, struct page *page,
		unsigned int len, unsigned int off);
int bio_iov_iter_get_pages(struct bio *bio, struct iov_iter *iter);
struct rq_map_data;
extern struct bio *bio_map_user_iov(struct request_queue *,
				    struct iov_iter *, gfp_t);
extern void bio_unmap_user(struct bio *);
extern struct bio *bio_map_kern(struct request_queue *, void *, unsigned int,
				gfp_t);
extern struct bio *bio_copy_kern(struct request_queue *, void *, unsigned int,
				 gfp_t, int);
extern void bio_set_pages_dirty(struct bio *bio);
extern void bio_check_pages_dirty(struct bio *bio);

void generic_start_io_acct(struct request_queue *q, int op,
				unsigned long sectors, struct hd_struct *part);
void generic_end_io_acct(struct request_queue *q, int op,
				struct hd_struct *part,
				unsigned long start_time);

#ifndef ARCH_IMPLEMENTS_FLUSH_DCACHE_PAGE
# error	"You should define ARCH_IMPLEMENTS_FLUSH_DCACHE_PAGE for your platform"
#endif
#if ARCH_IMPLEMENTS_FLUSH_DCACHE_PAGE
extern void bio_flush_dcache_pages(struct bio *bi);
#else
static inline void bio_flush_dcache_pages(struct bio *bi)
{
}
#endif

extern void bio_copy_data_iter(struct bio *dst, struct bvec_iter *dst_iter,
			       struct bio *src, struct bvec_iter *src_iter);
extern void bio_copy_data(struct bio *dst, struct bio *src);
extern void bio_list_copy_data(struct bio *dst, struct bio *src);
extern void bio_free_pages(struct bio *bio);

extern struct bio *bio_copy_user_iov(struct request_queue *,
				     struct rq_map_data *,
				     struct iov_iter *,
				     gfp_t);
extern int bio_uncopy_user(struct bio *);
void zero_fill_bio_iter(struct bio *bio, struct bvec_iter iter);

static inline void zero_fill_bio(struct bio *bio)
{
	zero_fill_bio_iter(bio, bio->bi_iter);
}

extern struct bio_vec *bvec_alloc(gfp_t, int, unsigned long *, mempool_t *);
extern void bvec_free(mempool_t *, struct bio_vec *, unsigned int);
extern unsigned int bvec_nr_vecs(unsigned short idx);
extern const char *bio_devname(struct bio *bio, char *buffer);

#define bio_set_dev(bio, bdev) 			\
do {						\
	if ((bio)->bi_disk != (bdev)->bd_disk)	\
		bio_clear_flag(bio, BIO_THROTTLED);\
	(bio)->bi_disk = (bdev)->bd_disk;	\
	(bio)->bi_partno = (bdev)->bd_partno;	\
} while (0)

#define bio_copy_dev(dst, src)			\
do {						\
	(dst)->bi_disk = (src)->bi_disk;	\
	(dst)->bi_partno = (src)->bi_partno;	\
} while (0)

#define bio_dev(bio) \
	disk_devt((bio)->bi_disk)

#if defined(CONFIG_MEMCG) && defined(CONFIG_BLK_CGROUP)
int bio_associate_blkcg_from_page(struct bio *bio, struct page *page);
#else
static inline int bio_associate_blkcg_from_page(struct bio *bio,
						struct page *page) {  return 0; }
#endif

#ifdef CONFIG_BLK_CGROUP
int bio_associate_blkcg(struct bio *bio, struct cgroup_subsys_state *blkcg_css);
int bio_associate_blkg(struct bio *bio, struct blkcg_gq *blkg);
void bio_disassociate_task(struct bio *bio);
void bio_clone_blkcg_association(struct bio *dst, struct bio *src);
#else	
static inline int bio_associate_blkcg(struct bio *bio,
			struct cgroup_subsys_state *blkcg_css) { return 0; }
static inline void bio_disassociate_task(struct bio *bio) { }
static inline void bio_clone_blkcg_association(struct bio *dst,
			struct bio *src) { }
#endif	

#ifdef CONFIG_HIGHMEM

static inline char *bvec_kmap_irq(struct bio_vec *bvec, unsigned long *flags)
{
	unsigned long addr;

	
	local_irq_save(*flags);
	addr = (unsigned long) kmap_atomic(bvec->bv_page);

	BUG_ON(addr & ~PAGE_MASK);

	return (char *) addr + bvec->bv_offset;
}

static inline void bvec_kunmap_irq(char *buffer, unsigned long *flags)
{
	unsigned long ptr = (unsigned long) buffer & PAGE_MASK;

	kunmap_atomic((void *) ptr);
	local_irq_restore(*flags);
}

#else
static inline char *bvec_kmap_irq(struct bio_vec *bvec, unsigned long *flags)
{
	return page_address(bvec->bv_page) + bvec->bv_offset;
}

static inline void bvec_kunmap_irq(char *buffer, unsigned long *flags)
{
	*flags = 0;
}
#endif


struct bio_list {
	struct bio *head;
	struct bio *tail;
};

static inline int bio_list_empty(const struct bio_list *bl)
{
	return bl->head == NULL;
}

static inline void bio_list_init(struct bio_list *bl)
{
	bl->head = bl->tail = NULL;
}

#define BIO_EMPTY_LIST	{ NULL, NULL }

#define bio_list_for_each(bio, bl) \
	for (bio = (bl)->head; bio; bio = bio->bi_next)

static inline unsigned bio_list_size(const struct bio_list *bl)
{
	unsigned sz = 0;
	struct bio *bio;

	bio_list_for_each(bio, bl)
		sz++;

	return sz;
}

static inline void bio_list_add(struct bio_list *bl, struct bio *bio)
{
	bio->bi_next = NULL;

	if (bl->tail)
		bl->tail->bi_next = bio;
	else
		bl->head = bio;

	bl->tail = bio;
}

static inline void bio_list_add_head(struct bio_list *bl, struct bio *bio)
{
	bio->bi_next = bl->head;

	bl->head = bio;

	if (!bl->tail)
		bl->tail = bio;
}

static inline void bio_list_merge(struct bio_list *bl, struct bio_list *bl2)
{
	if (!bl2->head)
		return;

	if (bl->tail)
		bl->tail->bi_next = bl2->head;
	else
		bl->head = bl2->head;

	bl->tail = bl2->tail;
}

static inline void bio_list_merge_head(struct bio_list *bl,
				       struct bio_list *bl2)
{
	if (!bl2->head)
		return;

	if (bl->head)
		bl2->tail->bi_next = bl->head;
	else
		bl->tail = bl2->tail;

	bl->head = bl2->head;
}

static inline struct bio *bio_list_peek(struct bio_list *bl)
{
	return bl->head;
}

static inline struct bio *bio_list_pop(struct bio_list *bl)
{
	struct bio *bio = bl->head;

	if (bio) {
		bl->head = bl->head->bi_next;
		if (!bl->head)
			bl->tail = NULL;

		bio->bi_next = NULL;
	}

	return bio;
}

static inline struct bio *bio_list_get(struct bio_list *bl)
{
	struct bio *bio = bl->head;

	bl->head = bl->tail = NULL;

	return bio;
}


static inline void bio_inc_remaining(struct bio *bio)
{
	bio_set_flag(bio, BIO_CHAIN);
	smp_mb__before_atomic();
	atomic_inc(&bio->__bi_remaining);
}


#define BIO_POOL_SIZE 2

struct bio_set {
	struct kmem_cache *bio_slab;
	unsigned int front_pad;

	mempool_t bio_pool;
	mempool_t bvec_pool;
#if defined(CONFIG_BLK_DEV_INTEGRITY)
	mempool_t bio_integrity_pool;
	mempool_t bvec_integrity_pool;
#endif

	
	spinlock_t		rescue_lock;
	struct bio_list		rescue_list;
	struct work_struct	rescue_work;
	struct workqueue_struct	*rescue_workqueue;

	ANDROID_KABI_RESERVE(1);
	ANDROID_KABI_RESERVE(2);
	ANDROID_KABI_RESERVE(3);
	ANDROID_KABI_RESERVE(4);
};

struct biovec_slab {
	int nr_vecs;
	char *name;
	struct kmem_cache *slab;
};

static inline bool bioset_initialized(struct bio_set *bs)
{
	return bs->bio_slab != NULL;
}


#define BIO_SPLIT_ENTRIES 2

#if defined(CONFIG_BLK_DEV_INTEGRITY)

#define bip_for_each_vec(bvl, bip, iter)				\
	for_each_bvec(bvl, (bip)->bip_vec, iter, (bip)->bip_iter)

#define bio_for_each_integrity_vec(_bvl, _bio, _iter)			\
	for_each_bio(_bio)						\
		bip_for_each_vec(_bvl, _bio->bi_integrity, _iter)

extern struct bio_integrity_payload *bio_integrity_alloc(struct bio *, gfp_t, unsigned int);
extern int bio_integrity_add_page(struct bio *, struct page *, unsigned int, unsigned int);
extern bool bio_integrity_prep(struct bio *);
extern void bio_integrity_advance(struct bio *, unsigned int);
extern void bio_integrity_trim(struct bio *);
extern int bio_integrity_clone(struct bio *, struct bio *, gfp_t);
extern int bioset_integrity_create(struct bio_set *, int);
extern void bioset_integrity_free(struct bio_set *);
extern void bio_integrity_init(void);

#else 

static inline void *bio_integrity(struct bio *bio)
{
	return NULL;
}

static inline int bioset_integrity_create(struct bio_set *bs, int pool_size)
{
	return 0;
}

static inline void bioset_integrity_free (struct bio_set *bs)
{
	return;
}

static inline bool bio_integrity_prep(struct bio *bio)
{
	return true;
}

static inline int bio_integrity_clone(struct bio *bio, struct bio *bio_src,
				      gfp_t gfp_mask)
{
	return 0;
}

static inline void bio_integrity_advance(struct bio *bio,
					 unsigned int bytes_done)
{
	return;
}

static inline void bio_integrity_trim(struct bio *bio)
{
	return;
}

static inline void bio_integrity_init(void)
{
	return;
}

static inline bool bio_integrity_flagged(struct bio *bio, enum bip_flags flag)
{
	return false;
}

static inline void *bio_integrity_alloc(struct bio * bio, gfp_t gfp,
								unsigned int nr)
{
	return ERR_PTR(-EINVAL);
}

static inline int bio_integrity_add_page(struct bio *bio, struct page *page,
					unsigned int len, unsigned int offset)
{
	return 0;
}

#endif 

#endif 
#endif 
