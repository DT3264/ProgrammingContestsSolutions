
// Problem : A. String Generation
// Contest : Codeforces - Codeforces Round #689 (Div. 2, based on Zed Code Competition)
// URL : https://codeforces.com/contest/1461/problem/0
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
    int n, k;
    cin >> cases;
    while(cases--){
    	cin >> n >> k;
    	char c='a';
    	while(n--){
    		if(c>'c') c='a';
    		cout << c;
    		c++;
    	}
    	cout << "\n";
    }
    return 0;
}
