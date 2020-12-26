
// Problem : L - Deque
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_l
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
template<class T>
using v=vector<T>;   
bool printDebug=false;
v<int> vec;
ll dp[3001][3001];
ll play(int l, int r){
	if(l>r) return 0;
	if(dp[l][r]!=-1) return dp[l][r];
	ll withL=vec[l]-play(l+1, r);
	ll withR=vec[r]-play(l, r-1);
	return dp[l][r]=max(withL, withR);
}
int main(){
    printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    int n;
    cin >> n;
    vec=vi(n);
    memset(dp, -1, sizeof(dp));
    for(int &x : vec) cin >> x;
    ll ans=play(0, n-1);
    cout << ans << "\n";
    return 0;
}
