#include<stdio.h>
int main(){
    long long n, m;
    scanf("%lld %lld", &n, &m);
    bool pp = false;
    if(m>(n/2)+(n%2==0?0:1)){
        m-=(n/2)+(n%2==0?0:1);
        pp=true;
    }
    long long res = (m*2)-1;
    if(pp) res++;
    printf("%lld\n", res);
    return 0;

}
