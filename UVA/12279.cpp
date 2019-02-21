#include<stdio.h>
int main(){
    int n, i;
    int actualCase=1;
    int balance=0, t;
    while(scanf("%d", &n) && n!=0){
        balance=0;
        for(i=0; i<n; i++){
            scanf("%d", &t);
            if(t>=1){
                balance++;
            }
            else{
                balance--;
            }
        }
        printf("Case %d: %d\n", actualCase++, balance);
    }
    return 0;
}

