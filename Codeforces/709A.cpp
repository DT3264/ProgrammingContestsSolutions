#include<stdio.h>
using namespace std;

int main(){
    long long n, b, d;
    long long i, t, oranges=0;
    long long overflow = 0;
    scanf("%lld %lld %lld", &n, &b, &d);
    for(i=0; i<n; i++){
        scanf("%lld", &t);
        if(t<=b) oranges+=t;
        if(oranges>d){
            oranges=0;
            overflow++;
        }
    }
    printf("%lld\n", overflow);
    return 0;
}
