
// Problem : G - Longest Path
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_g
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define y1 yy
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define v(t) vector<t>
#define pii pair<int, int>
#define debug if(printDebug)
#define noDebug if(!printDebug)
using namespace std;
bool printDebug=false;
v(vi) vec;
vi dp;
v(bool) used;
int move(int pos){
	if(used[pos]) return 0;
	if(dp[pos]!=-1) return dp[pos];
	used[pos]=1;
	int maxV=0;
	for(int &x : vec[pos]){
		if(used[x]) continue;
		maxV=max(maxV, move(x)+1);
	}
	used[pos]=0;
	return dp[pos]=maxV;
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    int n, m;
    int u, v;
    cin >> n >> m;
    vec=v(vi)(n+1);
    dp=vi(n+1, -1);
    used=v(bool)(n+1, 0);
    for(int i=0; i<m; i++){
    	cin >> u >> v;
    	vec[u].push_back(v);
    }
    int ans=0;
    for(int i=1; i<=n; i++){
    	ans=max(ans, move(i));
    }
    cout << ans << "\n";
    return 0;
}
