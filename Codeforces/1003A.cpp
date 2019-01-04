#include<stdio.h>
int n, t;
int buk[101];
int main(){
    int i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &t);
        buk[t]++;
    }
    int maxN=0;
    for(i=1; i<=100; i++){
        maxN=(maxN<buk[i] ? buk[i] : maxN);
    }
    printf("%d", maxN);
}
