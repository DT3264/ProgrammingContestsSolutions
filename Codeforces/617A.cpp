#include<stdio.h>
int n, minSteps=1000000, cont;
int main(){
    scanf("%d", &n);
    while(n>=5) n-=5, cont++;
    while(n>=4) n-=4, cont++;
    while(n>=3) n-=3, cont++;
    while(n>=2) n-=2, cont++;
    while(n>=1) n-=1, cont++;
    printf("%d", cont);
    return 0;
}
