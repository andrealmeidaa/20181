#include <stdio.h>

int main(){
    int n, h,min, m,s;
    scanf("%d",&n);
    h=n/3600;
    min=n%3600;
    m=min/60;
    s=min%60;
    printf("%d:%d:%d\n",h,m,s);
}
