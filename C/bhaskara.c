#include <stdio.h>
#include <math.h>

double delta(double a, double b, double c){
    double deltaParcial;
    deltaParcial=b*b-4*a*c;
    return deltaParcial;
}

int main(){
    double a,b,c,x1,x2,deltaParcial;
    scanf("%lf %lf %lf",&a,&b,&c);
    if (a==0.0){
        printf("Impossivel calcular\n");
    }else{
        deltaParcial=delta(a,b,c);
        if (deltaParcial<0.0){
            printf("Impossivel calcular\n");
        }else{
            x1=(-b+sqrt(deltaParcial))/(2*a);
            x2=(-b-sqrt(deltaParcial))/(2*a);
            printf("R1 = %0.5lf\n",x1);
            printf("R2 = %0.5lf\n",x2);
        }
    }
}