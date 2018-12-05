#include<stdio.h>
bool tNumbers[550];
int main(){
    int n, i, t=0;
    for(i=1; t<=500; i++){
        t+=i;
        tNumbers[t]=1;

    }
    scanf("%d", &n);
    printf(tNumbers[n] ? "YES" : "NO");
    return 0;
}
