/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM irq

#if !defined(_TRACE_IRQ_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_IRQ_H

#include <linux/tracepoint.h>

struct irqaction;
struct softirq_action;

#define SOFTIRQ_NAME_LIST				\
			 softirq_name(HI)		\
			 softirq_name(TIMER)		\
			 softirq_name(NET_TX)		\
			 softirq_name(NET_RX)		\
			 softirq_name(BLOCK)		\
			 softirq_name(IRQ_POLL)		\
			 softirq_name(TASKLET)		\
			 softirq_name(SCHED)		\
			 softirq_name(HRTIMER)		\
			 softirq_name_end(RCU)

#undef softirq_name
#undef softirq_name_end

#define softirq_name(sirq) TRACE_DEFINE_ENUM(sirq##_SOFTIRQ);
#define softirq_name_end(sirq)  TRACE_DEFINE_ENUM(sirq##_SOFTIRQ);

SOFTIRQ_NAME_LIST

#undef softirq_name
#undef softirq_name_end

#define softirq_name(sirq) { sirq##_SOFTIRQ, #sirq },
#define softirq_name_end(sirq) { sirq##_SOFTIRQ, #sirq }

#define show_softirq_name(val)				\
	__print_symbolic(val, SOFTIRQ_NAME_LIST)


TRACE_EVENT(irq_handler_entry,

	TP_PROTO(int irq, struct irqaction *action),

	TP_ARGS(irq, action),

	TP_STRUCT__entry(
		__field(	int,	irq		)
		__string(	name,	action->name	)
	),

	TP_fast_assign(
		__entry->irq = irq;
		__assign_str(name, action->name);
	),

	TP_printk("irq=%d name=%s", __entry->irq, __get_str(name))
);


TRACE_EVENT(irq_handler_exit,

	TP_PROTO(int irq, struct irqaction *action, int ret),

	TP_ARGS(irq, action, ret),

	TP_STRUCT__entry(
		__field(	int,	irq	)
		__field(	int,	ret	)
	),

	TP_fast_assign(
		__entry->irq	= irq;
		__entry->ret	= ret;
	),

	TP_printk("irq=%d ret=%s",
		  __entry->irq, __entry->ret ? "handled" : "unhandled")
);

DECLARE_EVENT_CLASS(softirq,

	TP_PROTO(unsigned int vec_nr),

	TP_ARGS(vec_nr),

	TP_STRUCT__entry(
		__field(	unsigned int,	vec	)
	),

	TP_fast_assign(
		__entry->vec = vec_nr;
	),

	TP_printk("vec=%u [action=%s]", __entry->vec,
		  show_softirq_name(__entry->vec))
);


DEFINE_EVENT(softirq, softirq_entry,

	TP_PROTO(unsigned int vec_nr),

	TP_ARGS(vec_nr)
);


DEFINE_EVENT(softirq, softirq_exit,

	TP_PROTO(unsigned int vec_nr),

	TP_ARGS(vec_nr)
);


DEFINE_EVENT(softirq, softirq_raise,

	TP_PROTO(unsigned int vec_nr),

	TP_ARGS(vec_nr)
);

DECLARE_EVENT_CLASS(tasklet,

	TP_PROTO(void *func),

	TP_ARGS(func),

	TP_STRUCT__entry(
		__field( void *,	func)
	),

	TP_fast_assign(
		__entry->func = func;
	),

	TP_printk("function=%ps", __entry->func)
);

DEFINE_EVENT(tasklet, tasklet_entry,

	TP_PROTO(void *func),

	TP_ARGS(func)
);

DEFINE_EVENT(tasklet, tasklet_exit,

	TP_PROTO(void *func),

	TP_ARGS(func)
);

DEFINE_EVENT(tasklet, tasklet_hi_entry,

	TP_PROTO(void *func),

	TP_ARGS(func)
);

DEFINE_EVENT(tasklet, tasklet_hi_exit,

	TP_PROTO(void *func),

	TP_ARGS(func)
);

#endif 


#include <trace/define_trace.h>
