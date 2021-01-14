#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
  printf(1, "Rodando programa de teste para dereferenciar ponteiro nulo...\n");
  int *p = 0x0;
  printf(1, "Valor: %d\n", *p);

  exit();
}