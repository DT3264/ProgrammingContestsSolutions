#include<stdio.h>
int main(){
    int n, i, cont=0;
    scanf("%d", &n);
    int temp;
    for(i=1; i<=n/2; i++){
        temp=n-i;
        if(((temp/i)*i)+i==n) cont++;
    }
    printf("%d", cont);
    return 0;
}
