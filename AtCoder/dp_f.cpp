
// Problem : F - LCS
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_f
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
string s1, s2;
struct State{
	int v;//Actual length
	int x, y;//Next state
	char c;//Char of this state
	bool canTake;//If this state is part of the ans
	bool operator<(const State &state)const{
		return state.v>=v;
	}
};
vector<vector<State>> dp;
State move(int p1, int p2){
	if(p1==s1.length() || p2==s2.length()) return {0, p1, p2, ' ', false};
	if(dp[p1][p2].v!=-1) return dp[p1][p2];
	State v1={move(p1+1, p2).v, p1+1, p2, ' ', false};
	State v2={move(p1, p2+1).v, p1, p2+1, ' ', false};
	State v3={-1, -1, -1};
	if(s1[p1]==s2[p2]) v3={move(p1+1, p2+1).v+1, p1+1, p2+1, s1[p1], true};
	return dp[p1][p2]=max(max(v1, v2), v3);
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    cin >> s1 >> s2;
    dp=vector<vector<State>>(s1.length()+1, vector<State>(s2.length()+1, {-1, -1, -1, ' ', false}));
    auto ans=move(0, 0);
    while(ans.x!=-1){
    	if(ans.canTake) cout << ans.c;
    	ans=dp[ans.x][ans.y];
    }
    return 0;
}
