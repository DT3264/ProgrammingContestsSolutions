
// Problem : D. Districts Connection
// Contest : Codeforces - Codeforces Round #677 (Div. 3)
// URL : https://codeforces.com/contest/1433/problem/D
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
#define um unordered_map
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
bool areAllEqual(vi &vec){
	for(int i=1; i<vec.size(); i++){
		if(vec[i]!=vec[i-1]) return false;
	}
	return true;
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	int n;
    	cin >> n;
    	vector<int> vec(n);
    	for(int &x : vec) cin >> x;
    	if(areAllEqual(vec)){
    		cout << "NO\n";
    	}
    	else{
    		cout << "YES\n";
    		vector<int> posOfVal0;
    		for(int i=1; i<n; i++){
    			if(vec[i]!=vec[0]){
    				cout << "1 " << i+1 << "\n";
    			}
    			else posOfVal0.push_back(i);
    		}
    		if(posOfVal0.size()>0){
    			int idxNon0=-1;
    			for(int i=1; i<n && idxNon0==-1; i++){
    				if(vec[i]!=vec[0]) idxNon0=i;
    			}
    			for(int &x : posOfVal0) cout << idxNon0+1 << " " << x+1 << "\n";
    		}
    	}
    }
    return 0;
}
