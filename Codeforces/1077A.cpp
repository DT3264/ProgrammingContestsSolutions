#include<stdio.h>
int main(){
    int n;
    long long a, b, c, steps1, steps2, i;
    scanf("%lld", &n);
    for(i=0; i<n; i++){
        scanf("%lld%lld%lld", &a, &b, &c);
        steps1=c/2;
        steps2=c/2;
        if(c%2!=0)  steps1++;
        //printf("%lld - %lld\n", (a*steps1), (b*steps2));
        printf("%lld\n", (a*steps1)-(b*steps2));
    }
    return 0;
}
