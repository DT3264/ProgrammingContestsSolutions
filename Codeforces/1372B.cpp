#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define si set<int>
#define y1 yy
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
ll gcd(ll a, ll b){
    if(a==0) return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return (a*b)/gcd(a, b);
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    ll n;
    cin >> n;
    while(n--){
        ll m;
        ll bestVal=1e9, ans=1e9;
        cin >> m;
        vector<ll> vec;
        for(ll i=1; i<=sqrt(m); i++){
            if(m%i==0){
                vec.push_back(i);
                vec.push_back(m/i);
            }
        }
        for(ll &x : vec){
            if(x==m) continue;
            ll mirror=m-x;
            ll actLCM=lcm(x, mirror);
            if(actLCM<bestVal){
                bestVal=actLCM;
                ans=mirror;
            }
        }
        cout << m-ans << " " << ans << "\n";
    }
    return 0;

}
