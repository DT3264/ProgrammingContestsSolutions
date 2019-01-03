#include<stdio.h>
int main(){
    int n, m, r;
    int total=0;
    scanf("%d%d%d", &n, &m, &r);
    while(r-->0){
        total+=(n*2)+((m-2)*2);
        n-=4;
        m-=4;

    }
    printf("%d", total);
}
