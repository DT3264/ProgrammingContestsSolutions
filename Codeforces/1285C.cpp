#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long mcd(long long a, long long b){
    return a==0 ? b: mcd(b%a, a);
}
long long lcm(long long a, long long b){
    return (a*b)/mcd(a, b);
}
int main(){
    ll n, i;
    ll ans=1e12;
    vector<ll> vec;
    cin >> n;
    for(i=1; i<sqrt(n)+1; i++){
        if(n%i==0 && lcm(i, n/i)==n){
            ans = min(ans, n/i);
        }
    }
    printf("%lld %lld\n", ans, n/ans);
return 0;
}
