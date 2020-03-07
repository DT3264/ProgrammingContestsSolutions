#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int rec(int p1, int p2){
	if(p1<=0 || p2<=0){
		return 0;
	}
	if(dp[p1][p2]!=-1){
		return dp[p1][p2];
	}
	int best=max(rec(p1-2, p2+1), rec(p1+1, p2-2))+1;
	dp[p1][p2]=best;
	return dp[p1][p2];
}
int main(){
	memset(dp, -1, sizeof(dp));
	int n, m;
	cin >> n >> m;
	cout << (n+m>2 ? rec(n, m) : 0) << endl;
    return 0;
}