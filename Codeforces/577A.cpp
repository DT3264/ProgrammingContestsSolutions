#include<stdio.h>
int main(){
    int n, m, cont=0;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        if(m%i==0  && m/i<=n){
            cont++;
        }
    }
    printf("%d\n", cont);
    return 0;
}
