#ifndef POINT_H
#define POINT_H

typedef struct Point Point;
typedef Point *Point_t;

struct Point {
    void (*set)(int x, int y);
    void (*print)(void);
};

Point_t newPoint(int x, int y);

#endif // !POINT_H
