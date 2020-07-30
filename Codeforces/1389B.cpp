// Problem : B. Array Walk
// Contest : Codeforces - Educational Codeforces Round 92 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1389/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
vector<int> vec;
vector<vector<vi>> dp;
int move(int pos, int moves, int canLeft, bool fromLeft){
	if(dp[canLeft][fromLeft][pos]!=-1){
		return dp[canLeft][fromLeft][pos];
	}
	if(moves==0) return 0;
	int lAns=0;
	if(!fromLeft && canLeft && pos>0){
		//To the left
		lAns=max(lAns, move(pos-1, moves-1, canLeft-1, 1)+vec[pos-1]);
	}
	//To the right
	lAns=max(lAns, move(pos+1, moves-1, canLeft, 0)+vec[pos+1]);
	return dp[canLeft][fromLeft][pos]=lAns;
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	int n, k, z;
    	cin >> n >> k >> z;
    	vec=vector<int>(n);
    	dp=vector<vector<vi>>(z+1, vector<vi>(2, vi(n, -1)));
    	for(int &x : vec) cin >> x;
    	cout << move(0, k, z, false)+vec[0] << "\n";
    }
    return 0;
}