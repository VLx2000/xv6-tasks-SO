#include "types.h"
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
}