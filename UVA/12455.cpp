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
int toFind, n;
vi vec;
bool func(int pos, int sum){
	if(sum>=toFind) return sum==toFind;
	if(sum==toFind) return true;
	if(pos>=n) return false;
	bool ans=false;
	if(func(pos+1, sum)) ans=true;
	else if(func(pos+1, sum+vec[pos])) ans=true;
	return ans;
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	cin >> toFind >> n;
    	vec=vi(n);
    	bool ans=(n==0);
    	for(int &x : vec){
    		cin >> x;
    		if(x==toFind) ans=true;
    	}
    	if(!ans) ans=func(0, 0);
    	cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}
