
// Problem : A. Favorite Sequence
// Contest : Codeforces - Codeforces Round #690 (Div. 3)
// URL : https://codeforces.com/contest/1462/problem/0
// Memory Limit : 256 MB
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
template<class T>
using v=vector<T>;   
bool printDebug=false;
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    int cases;
    cin >> cases;
    while(cases--){
    	int n;
    	cin >> n;
    	vi vec(n);
    	vi ans(n);
    	for(int &x : vec) cin >> x;
    	int l=0, r=n-1;
    	int aPos=0;
    	while(l<=r){
    		ans[aPos++]=vec[l++];
    		if(l<r) ans[aPos++]=vec[r--];
    	}
    	for(int &x : ans) cout << x << " ";
    	cout << "\n"; 
    }
    return 0;
}
