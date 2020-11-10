
// Problem : H - Grid 1
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_h
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
int n, m;
v(v(char)) grid;
v(v(ll)) dp;
ll mod=1000000000+7;
ll move(int x, int y){
	if(x>=n || y>=m || grid[x][y]=='#') return 0;
	if(x==n-1 && y==m-1) return dp[x][y]=1;
	if(dp[x][y]!=-1) return dp[x][y];
	int v1=0, v2=0;
	v1=move(x+1, y);
	v2=move(x, y+1);
	return dp[x][y]=(v1+v2)%mod;
	
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    cin >> n >> m;
    grid=v(v(char))(n, v(char)(m));
    dp=v(v(ll))(n, v(ll)(m, -1));
    for(int i=0; i<n; i++){
    	for(int j=0; j<m; j++) cin >> grid[i][j];
    }
    cout << move(0, 0) << "\n";
    return 0;
}
