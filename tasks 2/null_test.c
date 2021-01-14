#include "types.h"
#include "stat.h"
#include "user.h"
#define NULL ((void *)0)

int
main()
{
    int x, y;
    int *p;
    x = 1;
    p = &x;
    x = *p;
    *p = NULL;
    y = *p;
    printf(1, "Ponteiro NULO: %p", p);
    exit();
}