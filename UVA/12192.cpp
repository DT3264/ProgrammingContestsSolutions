
// Problem : 12192 - Grapevine
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3344
// Memory Limit : 32 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#pragma ("OFast")
#define y1 yy
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
int n, m;
void insertDiagonal(int i, int j, vector<vi> &vec, vector<vi> &diag, int actDiag){
	while(i<n && j<m){
		diag[actDiag].push_back(vec[i++][j++]);
	}
}

int getLower(int val, vi &vec){
	int l=0, r=vec.size()-1;
	int lastFound=-1;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(vec[mid]>=val){
			lastFound=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return lastFound;
}

int getUpper(int val, vi &vec){
	int l=0, r=vec.size()-1;
	int lastFound=-1;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(vec[mid]<=val){
			lastFound=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return lastFound;
}

int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int q;
    while(cin >> n >> m){
    	if(n+m==0) break;
    	vector<vi> vec(n, vi(m));
    	for(auto &v : vec){
    		for(auto &x : v) cin >> x;
    	}
    	vector<vi> diag(n+m-1);
    	int actDiag=0;
    	for(int j=0; j<m; j++){
    		insertDiagonal(0, j, vec, diag, actDiag++);
    	}
    	for(int i=1; i<n; i++){
    		insertDiagonal(i, 0, vec, diag, actDiag++);
    	}
    	int q, l, r;
    	cin >> q;
    	while(q--){
    		cin >> l >> r;
    		int ans=0;
    		for(auto &v : diag){
    			int lower=getLower(l, v);
    			int upper=getUpper(r, v);
    			if(lower!=-1 && upper!=-1){
    				ans=max(ans, upper-lower+1);
    			}
    		}
    		cout << ans << "\n";
    	}
    	cout << "-\n";
    }
    return 0;
}
