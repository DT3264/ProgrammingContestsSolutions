#include<stdio.h>
using namespace std;
int main(){
    long long a, b;
    long long total, rounds, remaining;
    while(scanf("%lld %lld", &a, &b)!=EOF){
        total = 0;
        while(a>=b){
            rounds = a/b;
            remaining = a%b;
            total+=rounds*b;
            a=remaining+rounds;
        }
        if(a>0) total+=a;
        printf("%lld\n", total);
    }
    return 0;
}
