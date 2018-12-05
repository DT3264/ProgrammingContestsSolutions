#include<stdio.h>
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int contDays=0;
    while(n>0){
        n--;
        contDays++;
        if(contDays%m == 0) n++;
    }
    printf("%d", contDays);
    return 0;
}
