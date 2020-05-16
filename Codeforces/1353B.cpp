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
    ll cases;
    cin >> cases;
    while(cases--){
        ll n, m;
        cin >> n >> m;
        vector<int> vecA(n), vecB(n);
        for(int &x : vecA) cin >> x;
        for(int &x : vecB) cin >> x;
        sort(vecA.begin(), vecA.end());
        sort(vecB.begin(), vecB.end());
        while(m-->0 && vecA[0]<vecB[vecB.size()-1]){
            vecA.erase(vecA.begin());
            vecA.push_back(vecB[vecB.size()-1]);
            sort(vecA.begin(), vecA.end());
            vecB.pop_back();
        }

        int ans=0;
        for(int x : vecA){
            ans+=x;
        }
        cout << ans << "\n";
    }
    return 0;
}
