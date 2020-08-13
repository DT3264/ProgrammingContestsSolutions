
// Problem : C. Boboniu and Bit Operations
// Contest : Codeforces - Codeforces Round #664 (Div. 2)
// URL : https://codeforces.com/contest/1395/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
int n, m;
int bestAns;
vector<int> v1, v2;
const int MAX=(1<<9);
int dp[MAX][MAX];
int mix(int pos, int val){
	if(dp[pos][val]!=-1) return dp[pos][val];
	if(pos==n){
		return val;
	}
	int minN=1e9;
	for(int i=0; i<m; i++){
		minN=min(minN, mix(pos+1, val|(v1[pos] & v2[i])));
	}
	return dp[pos][val]=minN;
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    cin >> n >> m;
    v1.resize(n);
    v2.resize(m);
    memset(dp, -1, sizeof(dp));
    for(int &x : v1) cin >> x;
    for(int &x : v2) cin >> x;
    cout << mix(0, 0) << "\n";
    return 0;
}
