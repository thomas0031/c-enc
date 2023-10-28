#include "point.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct _Point _Point;
typedef struct _Point *_Point_t;

struct _Point {
    int x;
    int y;
};

void point_set(int x, int y) {
    Point_t this;
    asm ("mov 24(%%rbp), %0" : "=r"(this));

    _Point_t _this = (_Point_t)(this + 1);
    _this->x = x;
    _this->y = y;
}

void point_print() {
    Point_t this;
    asm ("mov 24(%%rbp), %0" : "=r"(this));

    _Point_t _this = (_Point_t)(this + 1);
    printf("(%d, %d)\n", _this->x, _this->y);
}

Point_t newPoint(int x, int y) {
    Point_t p = malloc(sizeof(_Point) + sizeof(_Point_t));
    p->set = point_set;
    p->print = point_print;

    _Point_t _p = (_Point_t)(p + 1);
    _p->x = x;
    _p->y = y;

    return p;
}
