
// Problem : C. Number of Pairs
// Contest : Codeforces - Codeforces Round #725 (Div. 3)
// URL : https://codeforces.com/contest/1538/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
using namespace std;
template<class T>
using v=vector<T>;
ll tryWith(ll pos, v<ll> &vec, ll v1, ll v2){
	ll l=pos+1, r=vec.size()-1;
	ll bestS=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(vec[pos]+vec[mid]>=v1){
			bestS=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	l=pos+1, r=vec.size()-1;
	ll bestE=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(vec[pos]+vec[mid]<=v2){
			bestE=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	//cout << bestS << "-" << bestE << "\n";
	return (bestE!=-1 && bestS!=-1 ? (bestE+1-bestS) : 0);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	ll n, l, r;
    	cin >> n >> l >> r;
    	v<ll> vec(n);
    	for(ll &x : vec){
    		cin >> x;
    	}
    	sort(vec.begin(), vec.end());
    	ll ans=0;
    	for(ll i=0; i<n; i++){
    		//cout << "Con " << vec[i] <<  "-" << tryWith(i, vec, l, r) << "\n";
    		ans+=tryWith(i, vec, l, r);
    	}
    	cout << ans << "\n";
    }
    return 0;
}
