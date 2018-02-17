#include <stdio.h>

int main(){
    int a=20;
    int *ponteiro;

    ponteiro = &a;//Endereço da variável a
    printf("Endereço de Memória da Variável A=%x\n",&a);
    printf("Endereço armazenado no ponteiro=%x\n",ponteiro);
    printf("Valor associado ao ponteiro=%d\n",*ponteiro);
    a=15;
    printf("Valor associado ao ponteiro=%d\n",*ponteiro);

}