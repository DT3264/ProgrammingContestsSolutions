
// Problem : B. Unique Bid Auction
// Contest : Codeforces - Codeforces Round #686 (Div. 3)
// URL : https://codeforces.com/contest/1454/problem/B
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
    cin >> cases;
    int n;
    while(cases--){
    	cin >> n;
    	map<int, vi> idx;
    	int p;
    	for(int i=1; i<=n; i++){
    		cin >> p;
    		idx[p].push_back(i);
    	}
    	int ans=-1;
    	for(auto &p : idx){
    		if(p.s.size()==1){
    			ans=p.s[0];
    			break;
    		}
    	}
    	cout << ans << "\n";
    }
    return 0;
}
