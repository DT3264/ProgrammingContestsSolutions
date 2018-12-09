#include<stdio.h>
#define ll long long

ll countSteps(ll &actualPos, ll &lastPos, ll &houses){
    ll kk = 0;
    if(actualPos>lastPos){
        kk = actualPos-lastPos;
    }
    else if(actualPos<lastPos){
        kk = (actualPos+houses)-lastPos;
    }
    lastPos = actualPos;
    return kk;
}

int main(){
    ll i, houses, ttd;
    ll totalPasos = 0;
    scanf("%lld %lld", &houses, &ttd);
    ll actualPos, lastPos=1;
    for(i=0; i<ttd; i++){
        scanf("%lld", &actualPos);
        totalPasos += countSteps(actualPos, lastPos, houses);
    }
    printf("%lld\n", totalPasos);
    return 0;
}
