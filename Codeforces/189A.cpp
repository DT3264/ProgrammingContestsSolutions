
// Problem : A. Cut Ribbon
// Contest : Codeforces - Codeforces Round #119 (Div. 2)
// URL : https://codeforces.com/problemset/problem/189/A
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
int a, b, c;
vi cuts;
int cut(int n){
	if(n==0) return 0;
	if(n<0) return -1000000;
	if(cuts[n]!=-1) return cuts[n];
	int v1=cut(n-a)+1;
	int v2=cut(n-b)+1;
	int v3=cut(n-c)+1;
	cuts[n]=max(v1, max(v2, v3));
	return cuts[n];
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int n;
    cin >> n >> a >> b >> c;
    cuts=vi(5000, -1);
    cout << cut(n) << "\n";
    return 0;
}
