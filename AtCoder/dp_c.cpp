
// Problem : C - Vacation
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_c
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
vector<vi> vec;
vector<vi> dp;
int rest(int day, int last){
	if(day==n) return 0;
	if(last<=2 && dp[day][last]!=-1) return dp[day][last];
	int val=0;
	for(int i=0; i<3; i++){
		if(i==last) continue; 
		val=max(val, vec[day][i]+rest(day+1, i));
	}
	return last<=2 ? dp[day][last]=val : val;
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    cin >> n;
    vec=vector<vi>(n, vi(3));
    dp=vector<vi>(n, vi(3, -1));
    for(auto &v : vec){
    	cin >> v[0] >> v[1] >> v[2];
    }
    cout << rest(0, 3) << "\n";
    return 0;
}
