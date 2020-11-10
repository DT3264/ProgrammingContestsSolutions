
// Problem : I - Coins
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_i
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
double global=0;
int n;
v(double) vec;
v(v(double)) dp;
double toss(int pos, int remainTails){
	if(pos==n) return 1;
	if(dp[pos][remainTails]!=-1) return dp[pos][remainTails];
	double v1=toss(pos+1, remainTails)*vec[pos];
	double v2=(remainTails>0 ? toss(pos+1, remainTails-1)*(1.0-vec[pos]) : 0);
	return dp[pos][remainTails]=v1+v2;
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    cin >> n;
    int maxTails=n/2-(n%2==0);
    vec=v(double)(n);
    dp=v(v(double))(n, v(double)(n, -1));
    for(auto &v : vec){
    	cin >> v;
    }
    cout << fixed << setprecision(10) << toss(0, maxTails) << "\n";
    return 0;
}
