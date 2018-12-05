#include<stdio.h>
int a, b, c;
int main(){
    scanf("%d%d%d", &a, &b, &c);
    int ta=1, tb=2, tc=4;
    while(ta<a && tb<b && tc<c){
        ta++;
        tb=ta*2;
        tc=tb*2;
    }
    if(ta>a || tb>b || tc>c){
        ta--;
        tb=ta*2;
        tc=tb*2;
    }
    printf("%d\n", ta+tb+tc);
    return 0;
}
