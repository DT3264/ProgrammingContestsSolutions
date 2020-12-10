
// Problem : K - Stones
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_k
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
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    int n, k;
    cin >> n >> k;
    v<bool> dp(k+1);
	vi moves(n);
	for(int &x : moves) cin >> x;
	for(int stones=0; stones<=k; stones++){
	    for(int &x : moves){
	    	if(stones>=x && !dp[stones-x]) dp[stones]=true;
	    }
    }
    cout << (dp[k] ? "First" : "Second") << "\n";
    return 0;
}
