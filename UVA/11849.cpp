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
    int n, m;
    while((cin >> n >> m) && m!=0 && n!=0){
        map<int, int> mp;
        int ans=0, t;
        for(int i=0; i<n; i++){
            cin >> t;
            mp[t]++;
        }
        for(int i=0; i<m; i++){
			cin >> t;
            if(mp[t]>0) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
