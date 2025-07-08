/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef _TOUCHEVENTNOTIFY_H
#define _TOUCHEVENTNOTIFY_H

struct touch_event {
	struct timeval time;
	int x;
	int y;
	int fid;       
	char type;     
};

#define EVENT_TYPE_DOWN    'D'
#define EVENT_TYPE_MOVE    'M'
#define EVENT_TYPE_UP      'U'


int touch_event_register_notifier(struct notifier_block *nb);
int touch_event_unregister_notifier(struct notifier_block *nb);


void touch_event_call_notifier(unsigned long action, void *data);

#endif
