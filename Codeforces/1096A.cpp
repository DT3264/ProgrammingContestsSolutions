#include<stdio.h>
int main() {
     long long n, i, l, r;
     scanf("%lld", &n);
     for(i=0; i<n; i++){
        scanf("%lld%lld", &l, &r);
        printf("%lld %lld\n", l, l*2);
     }
     return 0;
 }