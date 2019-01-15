#include<stdio.h>
int main (){
    int n, i, t;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &t);
        printf("%s\n", (360%(180-t)==0 ? "YES" : "NO"));
    }
    return 0;
}