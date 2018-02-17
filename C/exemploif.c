#include <stdio.h>

int main(){
    int a=20,b=10;
    if(a>=b){
        a+=12;
    }else{
        b+=12;
    }
    printf("A=%d,B=%d",a,b);
}