#include<stdio.h>
#include<math.h>
int main (){
    long long n;
    scanf("%lld", &n);
    long long xC, yC;
    scanf("%lld %lld", &xC, &yC);
    long long kW = (xC-1)+(yC-1);
    long long kB = (n-xC)+(n-yC);
    //printf("%lld vs %lld\n", kW, kB);
    printf(kW<=kB ? "White" : "Black");
    return 0;
}
