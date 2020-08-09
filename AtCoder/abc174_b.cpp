
// Problem : B - Distance 
// Contest : AtCoder - AtCoder Beginner Contest 174
// URL : https://atcoder.jp/contests/abc174/tasks/abc174_b
// Memory Limit : 1024 MB
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
double dist(double x, double y){
	return sqrt((x*x)+(y*y));
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int n, d;
    int x, y;
    cin >> n >> d;
    int ans=0;
    for(int i=0; i<n; i++){
    	cin >> x >> y;
    	if(ceil(dist(x,y))<=d) ans++;
    }
    cout << ans << "\n";
    return 0;
}
