
// Problem : B. Minimum Product
// Contest : Codeforces - Codeforces Round #667 (Div. 3)
// URL : https://codeforces.com/contest/1409/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define y1 yy
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	ll a, b, x, y, n;
    	cin >> a >> b >> x >> y >> n;
    	ll a1=max(a-n, x);
    	ll rem1=n-(a-a1);
    	ll a2=max(b-rem1, y);
    	ll v1=a1*a2;
    	ll b1=max(b-n, y);
    	ll rem2=n-(b-b1);
    	ll b2=max(a-rem2, x);
    	ll v2=b1*b2;
    	cout << min(v1, v2) << "\n";
    }
    return 0;
}
