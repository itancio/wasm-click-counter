#include <stdio.h>

//#include <emscripten/emscripten.h>

struct ClickCounter {
    int clicks;
};

static struct ClickCounter counter = {0};

int click(int num, char *s) {
    printf("click called with args[%d, %s]\n", num, s);
    return ++counter.clicks;
}

int main() {
    puts("Hello Emscripten!");
}
