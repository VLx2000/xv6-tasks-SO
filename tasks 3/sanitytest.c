#include "types.h"
#include "stat.h"
#include "user.h"

#define EH_FILHO 0

int main(void)
{
  char *p = (char *)main;
  *p = 0;
  printf(1, "Valor de *p comeca com = %d\n", *p);
  printf(1, "\n\nProtegendo para escrita...\n\n\n");
  proteger(p, 1);
  printf(1, "Lendo. *p = %d\n", *p);
  int pid = fork();

  if (pid == EH_FILHO)
  {
    //wait();
    printf(1, "\n\nDesprotegendo para escrita...\n\n\n");
    desproteger(p, 1);

    printf(1, "Tentando escrever em main (eh para funcionar)...");
    *p = 1;
    printf(1, "Lendo. *p = %d\n", *p);
    exit();
  }
  else
  {
    wait();
    printf(1, "\n\nProtegendo para escrita...\n\n\n");
    proteger(p, 1);

    printf(1, "Tentando escrever em main (eh para dar erro)...");
    *p = 2; //o programa deve parar aqui
    printf(1, "Lendo. *p = %d\n", *p);
    exit();
  }
}