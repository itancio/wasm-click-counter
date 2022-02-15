#include "counter.h"

void counter_inc(struct Counter *c) {
    ++(c->count);
}
