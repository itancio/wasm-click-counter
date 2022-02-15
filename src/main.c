#include <stdio.h>
#include "counter.h"
//#include <emscripten/emscripten.h>

/* this file is the interface for JS */

struct Counter c;

int click(int num, char *s) {
    // pass some random args from JS just to show that it can be done
    printf("click called with args[%d, %s]\n", num, s);
    counter_inc(&c);
    return c.count;
}

int main() {
    puts("Hello Emscripten!");
}
