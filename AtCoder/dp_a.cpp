
// Problem : A - Frog 1
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_a
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
int n;
vector<int> cost;
vector<int> dp;
int jump(int pos){
	if(pos==n-1) return 0;
	if(dp[pos]!=-1) return dp[pos];
	int v1=1e9, v2=1e9;
	if(pos+1<n) v1=abs(cost[pos]-cost[pos+1])+jump(pos+1);
	if(pos+2<n) v2=abs(cost[pos]-cost[pos+2])+jump(pos+2);
	return dp[pos]=min(v1, v2);
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    cin >> n;
    cost=vi(n);
    dp=vi(n, -1);
    for(int &x : cost) cin >> x;
    cout << jump(0) << "\n";
    return 0;
}
