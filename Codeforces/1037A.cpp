#include <stdio.h>

int main(){
    long long n;
    scanf("%lld", &n);
    long long pot = 1, cont = 1;
    while(pot<n){
        cont++;
        pot*=2;
    }
    printf("%d", pot==n ? cont : cont-1);
    return 0;
}
