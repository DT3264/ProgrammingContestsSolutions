#include<stdio.h>
int main(){
    long long n, x, t;
    long long dk=0;
    char op;
    scanf("%lld%lld", &n, &x);
    for(int i=0; i<n; i++){
        scanf(" %c %lld", &op, &t);
        if(op=='+'){
            x+=t;
        }
        else{
            x-=t;
            if(x<0){
                x+=t;
                dk++;
            }
        }
    }
    printf("%lld %lld", x, dk);
    return 0;
}
