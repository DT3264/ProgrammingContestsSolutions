
// Problem : D. Colored Rectangles
// Contest : Codeforces - Educational Codeforces Round 93 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1398/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define y1 yy
#define f first
#define s second
#define ll long long
#define vi vector<ll>
#define pii pair<int, int>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
int red, green, blue;
vi vRed, vGreen, vBlue;
vector<bool> uRed, uGreen, uBlue;
ll dp[201][201][201];
ll rec(int r, int g, int b){
	if(r==red && g==green) return 0;
	if(r==red && b==blue) return 0;
	if(g==green && b==blue) return 0;
	if(dp[r][g][b]!=-1) return dp[r][g][b];
	ll op1=0, op2=0, op3=0;
	if(r<red && g<green) op1=(vRed[r]*vGreen[g])+rec(r+1, g+1, b);
	if(r<red && b<blue) op2=(vRed[r]*vBlue[b])+rec(r+1, g, b+1);
	if(g<green && b<blue) op3=(vGreen[g]*vBlue[b])+rec(r, g+1, b+1);
	ll toReturn=max(op1, op2);
	toReturn=max(toReturn, op3);
	dp[r][g][b]=toReturn;
	return dp[r][g][b];
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    memset(dp, -1, sizeof(dp));
    cin >> red >> green >> blue;
    vRed=vi(red);
    vGreen=vi(green);
    vBlue=vi(blue);
    uGreen=vector<bool>(red, 0);
    uGreen=vector<bool>(green, 0);
    uGreen=vector<bool>(blue, 0);
    for(ll &x : vRed) cin >> x;
    for(ll &x : vGreen) cin >> x;
    for(ll &x : vBlue) cin >> x;
    sort(vRed.rbegin(), vRed.rend());
    sort(vGreen.rbegin(), vGreen.rend());
    sort(vBlue.rbegin(), vBlue.rend());
    cout << rec(0, 0, 0) << "\n";
    return 0;
}
