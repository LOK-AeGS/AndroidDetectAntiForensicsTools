
#include <linux/muic/common/muic_notifier.h>
#include <linux/muic/common/muic.h>
#ifndef __S2M_PDIC_NOTIFIER_H__
#define __S2M_PDIC_NOTIFIER_H__

struct s2m_pdic_notifier_struct {
	muic_attached_dev_t attached_dev;
	muic_notifier_cmd_t cmd;
	struct blocking_notifier_head notifier_call_chain;
};

enum {
	S2M_PDIC_NOTIFY_DEV_MUIC,
	S2M_PDIC_NOTIFY_DEV_USB,
	S2M_PDIC_NOTIFY_DEV_CHARGER,
};

#define MUIC_NOTIFIER_BLOCK(name)	\
	struct notifier_block (name)


extern void s2m_pdic_notifier_attach_attached_dev(muic_attached_dev_t new_dev);
extern void s2m_pdic_notifier_detach_attached_dev(muic_attached_dev_t cur_dev);
extern void s2m_pdic_notifier_logically_attach_attached_dev(muic_attached_dev_t new_dev);
extern void s2m_pdic_notifier_logically_detach_attached_dev(muic_attached_dev_t cur_dev);
void s2m_pdic_notifier_attach_attached_jig_dev(muic_attached_dev_t new_dev);


extern int s2m_pdic_notifier_register(struct notifier_block *nb,
		notifier_fn_t notifier, muic_notifier_device_t listener);
extern int s2m_pdic_notifier_unregister(struct notifier_block *nb);

#endif
