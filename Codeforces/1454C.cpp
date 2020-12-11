
// Problem : C. Sequence Transformation
// Contest : Codeforces - Codeforces Round #686 (Div. 3)
// URL : https://codeforces.com/contest/1454/problem/C
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
    while(cases--){
    	int n;
    	cin >> n;
    	int val;
    	map<int, vi> mp;
    	for(int i=0; i<n; i++){
    		cin >> val;
    		mp[val].push_back(i);
    	}
    	int bestAns=1e9;
    	for(auto &p : mp){
    		int lAns=0;
    		auto &v=p.s;
    		for(int i=1; i<v.size(); i++){
    			if(v[i]!=v[i-1]+1) lAns++;
    		}
    		if(v[0]!=0) lAns++;
    		if(v[v.size()-1]!=n-1) lAns++;
    		bestAns=min(bestAns, lAns);
    	}
    	cout << bestAns << "\n";
    }
    return 0;
}
