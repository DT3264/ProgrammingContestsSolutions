
// Problem : B - Frog 2
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define y1 yy
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
#define noDebug if(!printDebug)
using namespace std;
bool printDebug=false;
int n, k;
vector<int> cost;
vector<int> dp;
int jump(int pos){
	if(pos==n-1) return 0;
	if(dp[pos]!=-1) return dp[pos];
	int val=1e9;
	for(int i=1; i<=k && i+pos<n; i++){
		if(i+pos<n) val=min(val, abs(cost[pos]-cost[i+pos])+jump(pos+i));
	}
	return dp[pos]=val;
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    cin >> n >> k;
    cost=vi(n);
    dp=vi(n, -1);
    for(int &x : cost) cin >> x;
    cout << jump(0) << "\n";
    return 0;
}