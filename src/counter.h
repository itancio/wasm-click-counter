#ifndef __COUNTER_H__
#define __COUNTER_H__

struct Counter {
    int count;
};

void counter_inc(struct Counter *c);

#endif
