#include<stdio.h>
int main (){
    long long n, k, f, t, bestJoy=-10000000000000, actualJoy;
    long long i;
    scanf("%lld %lld", &n, &k);
    for(i=0; i<n; i++){
        scanf("%lld %lld", &f, &t);
        if(t<=k){
            actualJoy=f;
        }
        else{
            actualJoy = f-(t-k);
        }
        if(actualJoy>bestJoy) bestJoy=actualJoy;
    }
    printf("%lld", bestJoy);
    return 0;
}
