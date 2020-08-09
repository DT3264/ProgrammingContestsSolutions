
// Problem : B. Gifts Fixing
// Contest : Codeforces - Codeforces Round #661 (Div. 3)
// URL : https://codeforces.com/contest/1399/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define si set<int>
#define y1 yy
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	int n;
    	cin >> n;
    	vector<ll> candies(n), oranges(n);
    	ll minC=1e9, minO=1e9;
    	ll ans=0;
    	for(ll &x : candies){
    		cin >> x;
    		minC=min(minC, x);
    	}
    	for(ll &x : oranges){
    		cin >> x;
    		minO=min(minO, x);
    	}
    	//cout << minC << " " << minO << "\n";
    	for(int i=0; i<n; i++){
    		ans+=max(candies[i]-minC, oranges[i]-minO);
    	}
    	cout << ans << "\n";
    }
    return 0;
}
