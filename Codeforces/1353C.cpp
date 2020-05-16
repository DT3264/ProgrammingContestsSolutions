#include<bits/stdc++.h>
#define f first
#define s second
#define vi vector<ll>
#define pii pair<ll, ll>
#define ll long long
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll> ans(500001);
    ll val=8, mult=1;
    for(int i=3; i<500001; i+=2){
        ans[i]=(val*mult)+ans[i-2];
        val+=8;
        mult++;
    }
    ll cases;
    cin >> cases;
    while(cases--){
        ll n, m;
        cin >> n;
        cout << ans[n] << "\n";
    }
    return 0;
}
