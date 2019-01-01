#include<stdio.h>
int main(){
    int a, b, c;
    int rA=1, rB=2, rC=3;
    scanf("%d%d%d", &a, &b, &c);
    while(rA<a && rB<b && rC<c){
        rA++;
        rB++,
        rC++;
    }
    printf("%d", rA+rB+rC);
    return 0;
}
