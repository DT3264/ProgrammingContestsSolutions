#include<stdio.h>
int a, b, n;
int x, y, tmp;
int main(){
    char op;
    scanf("%d", &n);
    while(n--){
        scanf(" %c%d%d", &op, &x, &y);
        if(x>y){
            tmp=x;
            x=y;
            y=tmp;
        }
        if(op=='+'){
            if(x>a){
                a=x;
            }
            if(y>b){
                b=y;
            }
        }
        else{
            printf("%s\n", (a<=x && b<=y ? "YES" : "NO"));
        }
    }
    return 0;
}

