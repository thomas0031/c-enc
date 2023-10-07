#include "foo.h"

#include <stdlib.h>

typedef struct foo_private {
    int data;
} foo_private;

int __attribute__((noinline)) get(void) {
    foo_t this;
    // THIS IS 100% "I KNOW WHAT I'M DOING" CODE
    // TOP LEVEL SECURITY EXPERTS HAVE BEEN CONSULTED
    // CANNOT BE EXPLOITED
    // NO WAY
    // CROSSPLATFORM
    // 100% PORTABLE
    // SUPER FAST
    // SUPER MAINTAINABLE
    // SUPER READABLE
    // SUPER EASY TO DEBUG
    // SUPER EASY TO UNDERSTAND
    // I USE ARCH BTW
    //
    // sorry mom
    asm ("mov 24(%%rbp), %0" : "=r"(this));
    foo_private *private = (foo_private*)(this + 1);

    return private->data;
}

void __attribute__((noinline)) set(int a) {
    foo_t this;
    asm ("mov 24(%%rbp), %0" : "=r"(this));
    foo_private *private = (foo_private*)(this + 1);

    private->data = a;
}

foo_t foo_new(void) {
    foo_t ctx = malloc(sizeof(foo) + sizeof(foo_private));

    if (!ctx) return NULL;

    ctx->get = get;
    ctx->set = set;

    foo_private *private = (foo_private*)(ctx + 1);
    private->data = 0;

    return ctx;
}
