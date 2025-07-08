

#ifndef _VSERVICES_BUFFER_H_
#define _VSERVICES_BUFFER_H_

#include <linux/types.h>
#include <linux/string.h>
#include <linux/slab.h>

struct vs_mbuf;


struct vs_string {
	char *ptr;
	size_t max_size;
};


static inline size_t
vs_string_copyout(char *dest, const struct vs_string *src, size_t max_size)
{
	size_t src_len = strnlen(src->ptr, src->max_size);

	if (max_size) {
		size_t dest_len = min(src_len, max_size - 1);

		memcpy(dest, src->ptr, dest_len);
		dest[dest_len] = '\0';
	}
	return src_len;
}


static inline size_t
vs_string_copyin_len(struct vs_string *dest, const char *src, size_t max_size)
{
	strncpy(dest->ptr, src, min(max_size, dest->max_size));

	return strnlen(dest->ptr, dest->max_size);
}


static inline size_t
vs_string_copyin(struct vs_string *dest, const char *src)
{
	return vs_string_copyin_len(dest, src, dest->max_size);
}


static inline size_t
vs_string_length(struct vs_string *str)
{
	return strnlen(str->ptr, str->max_size);
}


static inline char *
vs_string_dup(struct vs_string *str, gfp_t gfp)
{
	size_t len;
	char *ret;

	len = strnlen(str->ptr, str->max_size) + 1;
	ret = kmalloc(len, gfp);
	if (ret)
		vs_string_copyout(ret, str, len);
	return ret;
}


static inline size_t
vs_string_max_size(struct vs_string *str)
{
	return str->max_size;
}


struct vs_pbuf {
	void *data;
	size_t size, max_size;
};


static inline size_t vs_pbuf_size(const struct vs_pbuf *pbuf)
{
	return pbuf->size;
}


static inline const void *vs_pbuf_data(const struct vs_pbuf *pbuf)
{
	return pbuf->data;
}


static inline ssize_t vs_pbuf_resize(struct vs_pbuf *pbuf, size_t size)
{
	if (size > pbuf->max_size)
		return -EOVERFLOW;

	pbuf->size = size;
	return size;
}


static inline ssize_t vs_pbuf_copyin(struct vs_pbuf *pbuf, off_t offset,
		const void *data, size_t nbytes)
{
	if (offset + nbytes > pbuf->size)
		return -EOVERFLOW;

	memcpy(pbuf->data + offset, data, nbytes);

	return nbytes;
}


static inline ssize_t vs_pbuf_append(struct vs_pbuf *pbuf,
		const void *data, size_t nbytes)
{
	if (pbuf->size + nbytes > pbuf->max_size)
		return -EOVERFLOW;

	memcpy(pbuf->data + pbuf->size, data, nbytes);
	pbuf->size += nbytes;

	return pbuf->size;
}


static inline char *vs_pbuf_dup_string(struct vs_pbuf *pbuf, gfp_t gfp_flags)
{
	return kstrndup(pbuf->data, pbuf->size, gfp_flags);
}

#endif 
