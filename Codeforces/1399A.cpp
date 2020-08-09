
// Problem : A. Remove Smallest
// Contest : Codeforces - Codeforces Round #661 (Div. 3)
// URL : https://codeforces.com/contest/1399/problem/A
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
    	vector<int> vec(n);
    	for(int &x : vec) cin >> x;
    	sort(vec.begin(), vec.end());
    	bool can=true;
    	for(int i=1; i<n; i++){
    		if(vec[i]-vec[i-1]>1) can=false;
    	}
    	cout << (can ? "YES" : "NO") << "\n";
    }
    return 0;
}
