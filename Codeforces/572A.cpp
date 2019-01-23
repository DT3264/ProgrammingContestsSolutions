#include<stdio.h>
int na, nb;
int k, m;
int arrA[100001], arrB[100001];
int main (){
    int i;
    scanf("%d%d", &na, &nb);
    scanf("%d%d", &k, &m);
    for(i=0; i<na; i++){
        scanf("%d", &arrA[i]);
    }
    for(i=0; i<nb; i++){
        scanf("%d", &arrB[i]);
    }
    printf("%s\n", (arrA[k-1]<arrB[nb-m] ? "YES" : "NO"));
    return 0;
}
