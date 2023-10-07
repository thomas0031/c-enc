#include "include/foo.h"

#include <stdio.h>

int main(void)
{
    foo_t foo = foo_new();

    printf("foo->get() = %d\n", foo->get());
    foo->set(42);
    printf("foo->get() = %d\n", foo->get());

    return 0;
}
