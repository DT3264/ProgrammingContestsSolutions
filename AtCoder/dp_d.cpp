
// Problem : D - Knapsack 1
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_d
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define y1 yy
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define debug if(printDebug)
#define noDebug if(!printDebug)
using namespace std;
bool printDebug=false;
vector<pii> vec;
vector<vl> dp;
int n, w;
ll take(int pos, int capacity){
	if(pos==n) return 0;
	if(dp[pos][capacity]!=-1) return dp[pos][capacity];
	ll v1=0, v2=0;
	if(capacity-vec[pos].f>=0) v1=vec[pos].s+take(pos+1, capacity-vec[pos].f);
	v2=take(pos+1, capacity);
	return dp[pos][capacity]=max(v1, v2);
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    cin >> n >> w;
	dp=vector<vl>(n, vl(w+1, -1));
    vec=vector<pii>(n);
    for(auto &p : vec) cin >> p.f >> p.s;
    cout << take(0, w);
    return 0;
}
