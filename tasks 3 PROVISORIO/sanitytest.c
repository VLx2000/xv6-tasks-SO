/*#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
    char* p;
    p =(char*)main;  
    fork();
    printf(1,"Endereco main %x\n",p[0]);
    p[0] = 0x0; 
    printf(1,"Tentando acessar 0x0: %x\n",p[0]);

    exit();
}*/

#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"
int
main(int argc, char *argv[])
{
  
  char *start = sbrk(0);
  sbrk(PGSIZE);
  *start=100;
  mprotect(start, 1) ;
  int child=fork();
  if(child==0){
	printf(1, "protected value = %d\n",*start); 
        munprotect(start, 1) ;  
        *start=5;
        printf(1, "After unprotecting the value became = %d\n",*start); 
        exit();
  }
  else if(child>0){
        wait();
        printf(1, "\nWatch this,I'll trap now\n"); 
        *start=5; 
        printf(1, "\nThis statement will not be printed\n");
        exit(); 
  } 
  //char arr[]={'1','2','3','4'};
  //arr[0]='a';
  /*printf(1,"\narr[0] = %d\n",arr[0]);
  mprotect((void *)(((uint)arr/PGSIZE)*PGSIZE),1);
  printf(1,"reched here \n");
//  munprotect((void *)(((uint)arr/PGSIZE-1)*PGSIZE),1);
  arr[0]='b';
   printf(1,"\narr[0] = %d\n",arr[0]);
  */ 
 exit();
}
