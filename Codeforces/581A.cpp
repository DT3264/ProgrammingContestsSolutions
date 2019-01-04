#include<stdio.h>
#include<math.h>
int a, b, i, contDiff, contSame;
int minN(int a, int b){
    return a<=b ? a : b;
}
int main(){
    scanf("%d%d", &a, &b);
    contDiff=minN(a, b);
    a-=contDiff;
    b-=contDiff;
    contSame+=floor(a/2);
    contSame+=floor(b/2);
    printf("%d %d", contDiff, contSame);
}
