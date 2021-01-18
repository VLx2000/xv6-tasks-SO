// Test that fork fails gracefully.
// Tiny executable so that the limit can be filling the proc table.

#include "types.h"
#include "stat.h"
#include "user.h"

#define N  1000
/*
void
printf(int fd, const char *s, ...)
{
  write(fd, s, strlen(s));
}
*/

// Variável Global compartilhada pelos pai e filhos
int shared_var = 1;

void
cowforktest(void)
{
  int n, pid;

  printf(1, "Testando cowfork implementado\n");

  for(n=0; n<N; n++){
    pid = cowfork();
    if(pid < 0)
      break;
    if(pid == 0)
      exit();
  }

  if(n == N){
    printf(1, "fork claimed to work N times!\n", N);
    exit();
  }

  for(; n > 0; n--){
    if(wait() < 0){
      printf(1, "wait stopped early\n");
      exit();
    }
  }

  if(wait() != -1){
    printf(1, "wait got too many\n");
    exit();
  }

  printf(1, "fork test OK\n");
}


void test_cow1() {

  printf(1, "%d paginas livres antes da chamada fork\n", getNumFreePages());
  printf(1, "Pai e Filho compartilham da variavel global -> shared_var\n");

  // chamando fork
  int pid = cowfork();

  if (pid < 0) {
    printf(1, "Falha no teste_cow 1\n");
  }

  // Filho
  if (pid == 0) {

    // Antes
    printf(1, "Processo Filho: var = %d\n", shared_var);
    printf(1, "%d paginas livres ANTES de realizarmos alteracoes\n", getNumFreePages());

    shared_var = 2;

    // Depois
    printf(1, "Processo Filho: var = %d\n", shared_var);
    printf(1, "%d paginas livres DEPOIS de realizarmos alteracoes\n", getNumFreePages());
    exit();
  }

    // Pai
    printf(1, "Processo pai: var = %d\n", shared_var);
    
    wait(); // Espera o processo filho terminar
    
    printf(1, "Processo pai: var = %d\n", shared_var);
    printf(1, "%d paginas livres apos esperar o processo filho terminar\n", getNumFreePages());
    return;

}

int
main(void)
{

  printf(1, "***************  PRIMEIRO TESTE  ***************\n");
  printf(1,"Primeiro Teste: forktest padrao\n");
  cowforktest();
  printf(1, "Primeiro Teste Finalizado!!!\n");

  printf(1, "***************  SEGUNDO TESTE  ***************\n");
  printf(1,"Segundo Teste: test_cow 1\n");
  test_cow1();
  printf(1, "Segundo Teste Finalizado!!!\n");

  exit();
}
