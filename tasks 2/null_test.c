#include "syscall.h"
#include "types.h"
#include "user.h"

#define NULL 0x0

int main()
{
    printf(1, "Rodando programa de teste para ponteiro nulo...\n");
    int *p = NULL;
    printf(1, "*p: %d \n",*p);
    exit();
}