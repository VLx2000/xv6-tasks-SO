#include "types.h"
#include "stat.h"
#include "user.h"
#include "defs.h"

int main(void)
{
  cprintf("rodando o programa de teste do ponteiro nulo...\n");
  int *p = 0x0;
  *p = 0;
  exit();
}