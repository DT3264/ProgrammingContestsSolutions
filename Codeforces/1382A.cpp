
// Problem : A. Common Subsequence
// Contest : Codeforces - Codeforces Round #658 (Div. 2)
// URL : https://codeforces.com/contest/1382/problem/0
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
    	int n, m;
    	cin >> n >> m;
    	vi v1(n), v2(m);
    	map<int, int> cont;
    	int ans=-1;
    	for(int &x : v1) cin >> x, cont[x]++;
    	for(int &x : v2){
    		cin >> x;
    		if(cont[x] && ans==-1){
    			ans=x;
    		}
    	}
    	if(ans==-1) cout << "NO\n";
    	else cout << "YES\n" << "1 " <<  ans << "\n";
    }
    return 0;
}
