// Problem : E - Knapsack 2
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define y1 yy
#define f first
#define s second
#define ll long long
#define vi vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define debug if(printDebug)
#define noDebug if(!printDebug)
using namespace std;
bool printDebug=false;
const ll INF=1e18;
const ll MAX_SUM=100000;
vi w, v;
vector<vi> dp;
ll n, c;
//Returns the min capacity used to reach a given value
ll take(ll pos, ll val) {
	if (val<=0) return 0;
	if (pos==n) return INF;
	if (dp[pos][val]!=-1) return dp[pos][val];
	ll v1=w[pos]+take(pos+1, val-v[pos]);
	ll v2=take(pos+1, val);
	return dp[pos][val]=min(v1, v2);
}

int main(){     
	cin >> n >> c;
	w=vi(n), v=vi(n);
	dp=vector<vi>(n, vi(MAX_SUM+1, -1));
	for (int i=0; i<n; i++) cin >> w[i] >> v[i];
	ll ans=0;
	int l=0, r=MAX_SUM;
	while(l<=r){
		int mid=(l+r)/2;
		//Test if the min capacity to reach mid is <= our max allowed
		if(take(0, mid)<=c){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout << ans << "\n";
}
