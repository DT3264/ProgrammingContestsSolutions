#include<bits/stdc++.h>
#define f first
#define s second
#define vi vector<ll>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sortVec sort(vec.begin(), vec.end());
#define debug if(printDebug)
bool printDebug=false;
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n;
    while(cin >> n && n!=0){
        multiset<ll> ms;
        map<ll, ll> mapa;
        ll ans=0;
        ll p, t;
        for(int i=0; i<n; i++){
            cin >> p;
            for(int i=0; i<p; i++){
                cin >> t;
                mapa[t]++;
                ms.insert(t);
            }
            ll v1=*ms.rbegin();
            ll v2=*ms.begin();
            if(mapa[v1]>0)mapa[v1]--;
            if(mapa[v2]>0)mapa[v2]--;
            if(mapa[v1]==0) ms.erase(v1);
            if(mapa[v2]==0) ms.erase(v2);
            ans+=v1-v2;
        }
        cout << ans << "\n";
    }
    return 0;
}
