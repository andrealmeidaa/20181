#include <stdio.h>

int soma(int a, int b){
    return a+b;
}
int main(){
    int a,b,c;
    printf("Digite o primeiro número:");
    scanf("%d",&a);
    printf("Digite o segundo número:");
    scanf("%d",&b);
    c=soma(a,b);
     printf("O resultado da soma é %d \n",c);
}