#include<stdio.h>
int main(){
    int n, m;
    int usedCandles=0;
    scanf("%d%d", &n, &m);
    while(n>0){
        n--, usedCandles++;
        if(usedCandles%m==0) n++;
    }
    printf("%d", usedCandles);
    return 0;
}
