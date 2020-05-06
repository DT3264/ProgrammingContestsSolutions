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
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ll n;
    while(cin >> n){
        ll corners=(1<<n);
        vector<ll> vec(corners, 0);
        ll cornerWeight;
        for(ll i=0; i<corners; i++){
            cin >> cornerWeight;
            for(ll j=0; j<n; j++){
                ll adjacentCorner=i^(1<<j);
                vec[adjacentCorner]+=cornerWeight;
            }
        }
        ll ans=0;
        for(ll i=0; i<corners; i++){
            for(ll j=0; j<n; j++){
                ll adjacentCorner=i^(1<<j);
                ll actSum=vec[adjacentCorner]+vec[i];
                ans=max(ans, actSum);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
