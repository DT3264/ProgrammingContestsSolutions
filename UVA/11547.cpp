#include<stdio.h>
using namespace std;
int main(){
    int n, i, num, cont;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &num);
        cont=0;
        num = (((((num*567)/9)+7492)*235)/47)-498;
        if(num<0) num*=-1;
        num = num%100;
        while(num>=10){
            num-=10;
            cont++;
        }
        printf("%d\n", cont);
    }
    return 0;
}
