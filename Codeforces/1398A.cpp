
// Problem : A. Bad Triangle
// Contest : Codeforces - Educational Codeforces Round 93 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1398/problem/A
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	int n;
    	cin >> n;
    	vector<ll> vec(n);
    	for(ll &x : vec) cin >> x;
    	if(vec[0]+vec[1]>vec[n-1]){
    		cout << "-1\n";
    	}
    	else{
    		cout << "1 2 " << n << "\n";
    	}
    	//cout << vec[0]+vec[1] << " vs " << vec[n-1] << "\n";
    }
    return 0;
}
