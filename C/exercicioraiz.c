#include <stdio.h>
#include <math.h>
/*gcc exercicioraiz.c -o raiz -lm*/
int main(){
    int numero01,numero02,i;
    double raiz,elemento;
    printf("Digite um número inteiro:");
    scanf("%d",&numero01);
    printf("Digite um número inteiro:");
    scanf("%d",&numero02);
    for(i=numero01;i<=numero02;i++){
        raiz=sqrt(i);
        printf("%0.2f\n",raiz);
    }
}