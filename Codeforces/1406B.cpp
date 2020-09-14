// Problem : B. Maximum Product
// Contest : Codeforces - Codeforces Round #670 (Div. 2)
// URL : https://codeforces.com/contest/1406/problem/B
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define y1 yy
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
ll getV(int left, int right, vll &vec){
	ll val=LLONG_MIN;
	int posLeft=0, posRight=vec.size()-1;
	while(left>0){
		if(val==LLONG_MIN) val=vec[posLeft];
		else val*=vec[posLeft];
		left--;
		posLeft++;
	}
	while(right>0){
		if(val==LLONG_MIN) val=vec[posRight];
		else val*=vec[posRight];
		right--;
		posRight--;
	}
	return val;
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	int n;
    	cin >> n;
    	vll vec(n);
    	for(ll &x : vec) cin >> x;
    	sort(vec.begin(), vec.end());
    	int left=0, right=5;
    	ll ans=LLONG_MIN;
    	for(int i=0; i<6; i++){
    		ans=max(ans, getV(left++, right--, vec));
    	}
    	cout << ans << "\n";
    }
    return 0;
}