#include<stdio.h>
int main(){
    int n, m, a, b, i, cont=0;
    scanf("%d%d", &n, &m);
    for(i=0; i<n*m; i++){
        scanf("%d%d", &a, &b);
        if(a || b){
            cont++;
        }
    }
    printf("%d", cont);
    return 0;
}
