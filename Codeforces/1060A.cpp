#include<stdio.h>
int i;
int n, buk[11], c8;
char t;

int contActN=0;
int contPosN=0;
int nToRemove=0;
int main(){
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf(" %c", &t);
        if(t-'0'==8) c8++;
        else buk[t-'0']++;
    }
    while(c8>0 && n>=11 && nToRemove<=9){
        c8--, n--, contActN++;
        while(buk[nToRemove]==0 & nToRemove<=9) nToRemove++;
        while(buk[nToRemove]>0){
            buk[nToRemove]--, n--, contActN++;
            if(contActN==11){
                contPosN++;
                contActN=0;
                break;
            }
            while(buk[nToRemove]==0 & nToRemove<=9) nToRemove++;
        }
    }
    if(contActN==11) contActN=0, contPosN++;
    while(c8>0){
        c8--, contActN++;
        if(contActN==11) contActN=0, contPosN++;
    }
    printf("%d", contPosN);
    return 0;
}