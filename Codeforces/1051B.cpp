#include<stdio.h>
#define ll long long
int main(){
    long long a, b, i, j;
    scanf("%lld%lld", &a, &b);
    printf("YES\n");
    for(i=a; i<=b; i+=2){
        printf("%lld %lld\n", i, i+1);
    }
    return 0;
}
