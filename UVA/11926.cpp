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
    ll n, m;
    ll u, v, t;
    while(cin >> n >> m){
        if(n==0 && m==0) break;
        bitset<1000001> bs;
        bool overlap=false;
        for(ll i=0; i<n; i++){
            cin >> u >> v;
            for(ll j=u; j<v && j<bs.size() && !overlap; j++){
                if(!bs[j]){
                    bs[j]=true;
                }
                else{
                    overlap=true;
                }
            }
        }
        for(ll i=0; i<m; i++){
            cin >> u >> v >> t;
            while(u<bs.size() && !overlap){
                for(ll j=u; j<v && j<bs.size() && !overlap; j++){
                    if(!bs[j]){
                        bs[j]=true;
                    }
                    else{
                        overlap=true;
                    }
                }
                u+=t;
                v+=t;
            }
        }
        cout << (overlap ? "CONFLICT" : "NO CONFLICT") << "\n";
    }
    return 0;
}
