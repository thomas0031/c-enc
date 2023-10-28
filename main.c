#include "include/point.h"

#include <stddef.h>
#include <stdio.h>

int main(void)
{
    Point_t p = newPoint(1, 2);

    p->print();
    p->set(3, 4);
    p->print();

    return 0;
}
