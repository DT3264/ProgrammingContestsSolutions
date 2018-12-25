#include<stdio.h>
int main(){
    int a;
    int l1=1, l2=2, l3=2;
    scanf("%d", &a);
    a--;
    while(a-->0){
        l1+=l2;
        l2+=l3++;
    }
    printf("%d", l1);
    return 0;
}
