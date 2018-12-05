#include<stdio.h>
#include<string.h>
long long n, i, cont;
char str[101];
int buk[150];
int s19Pos;
int main(){
    scanf(" %s", str);
    int strLen = strlen(str);
    for(i=0; i<strLen; i++){
        buk[str[i]]++;
        ///printf("%d ", str[i]);
    }
    bool can19 = true;
    ///3n / 3e / 1i / 1t
    while(buk['n']>=3 && buk['e']>=3 && buk['i']>=1 && buk['t']>=1){
        ///removes two since the third could be the beinin of the next one
        buk['n']-=2, buk['e']-=3, buk['i']--, buk['t']--;
        cont++;
    }
    printf("%lld", cont);
    return 0;
}



