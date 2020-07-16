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
int main(){
    //printDebug=true;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	ll n, m;
    	cin >> n >> m;
    	ll val=min(n, m);
    	val-=n<=m;
    	ll ans=(val*(val+1))/2;
    	ans+=m>=n;
    	cout << ans << "\n";
    }
    return 0;
}
