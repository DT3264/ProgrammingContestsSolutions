#include<stdio.h>

bool table[100001];
int canUse[100000];
int canUseN=0;

int main (){
    int n, i, j, k, t;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &table[i]);
    }
    canUse[canUseN++]=1;
    for(i=2; i<n/2; i++){
        if(n%i==0)
        canUse[canUseN++]=i;
    }
    bool areAllHappy=false;
    bool actualAreHappy;
    for(i=0; i<canUseN && !areAllHappy; i++){
        for(j=0; j<canUse[i] && !areAllHappy; j++){
            actualAreHappy=true;
            for(k=j; k<n; k+=canUse[i]){
                if(!table[k]) actualAreHappy=false;
                ///printf("%d ", k);
            }
            if(actualAreHappy) areAllHappy=true;
            ///printf("\n");
        }
    }
    printf(areAllHappy ? "YES" : "NO");
    return 0;
}
