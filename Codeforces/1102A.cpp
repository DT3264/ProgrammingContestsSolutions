#include<stdio.h>
long long n;
int main(){
    scanf("%lld", &n);
    n=(n*(n+1))/2;
    printf("%d", n%2);
    return 0;
}