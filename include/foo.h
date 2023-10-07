#ifndef FOO_H
#define FOO_H

typedef struct foo {
    int (*get)(void);
    void (*set)(int);
} foo;

typedef foo *foo_t;

foo_t foo_new(void);

#endif // !FOO_H
