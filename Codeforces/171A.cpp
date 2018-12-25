#include<stdio.h>
long long a, b, tb, pot10=1, tpot, total;
int main(){
    scanf("%lld%lld", &a, &b);
    tb=b;
    while(tb>0){
        //printf("%d ", tb%10);
        tb/=10;
        tpot++;
    }
    tb=b;
    tpot--;
    while(tpot-->0){
        pot10*=10;
    }
    total+=a;
    while(tb>0){
        //printf("%d ", (tb%10)*pot10);
        total+=(tb%10)*pot10;
        tb/=10;
        pot10/=10;
        tpot++;
    }
    printf("%lld", total);
    return 0;
}
