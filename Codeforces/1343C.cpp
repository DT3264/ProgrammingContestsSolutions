#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ll n, m, t;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> m;
        vector<vector<ll>> vec;
        cin >> t;
        vec.push_back(vector<ll>(1, t));
        for(int i=1; i<m; i++){
            cin >> t;
            if((t>=0 && vec[vec.size()-1][0]<0) || t<0 && vec[vec.size()-1][0]>=0){
                vec.push_back(vector<ll>(1, t));
            }
            else{
                vec[vec.size()-1].push_back(t);
            }
        }
        ll sum=0;
        for(auto &v : vec){
            ll maxN=-(1e9);
            for(auto &x : v){
                maxN=max(maxN, x);
            }
            sum+=maxN;
        }
        cout << sum << "\n";
    }
	return 0;

}
