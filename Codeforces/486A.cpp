#include<stdio.h>
int main(){
    long long n, ans;
    scanf("%lld", &n);
    bool isOdd = n%2==0;
    ans = n;
    if(!isOdd){
        ans++;
    }
    ans/=2;
    printf("%lld", ans * (isOdd ? 1 : -1));
    return 0;
}