#include<stdio.h>
int main(){
    int n, i, a, cont=0;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &a);
        if(a==1) cont++;
    }
    printf(cont>0?"HARD":"EASY");
    return 0;
}

