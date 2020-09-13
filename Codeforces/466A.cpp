
// Problem : A. Cheap Travel
// Contest : Codeforces - Codeforces Round #266 (Div. 2)
// URL : https://codeforces.com/problemset/problem/466/A
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
int n, m, a, b;
vi sum;
int travel(int pos){
	if(pos>=n) return 0;
	if(sum[pos]!=-1) return sum[pos];
	int v1=a+travel(pos+1);
	int v2=b+travel(pos+m);
	sum[pos]=min(v1, v2);
	return sum[pos];
	
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    cin >> n >> m >> a >> b;
    sum=vi(n+1, -1);
    cout << travel(0) << "\n";
    return 0;
}
