
// Problem : D. Divide and Summarize
// Contest : Codeforces - Codeforces Round #689 (Div. 2, based on Zed Code Competition)
// URL : https://codeforces.com/contest/1461/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define y1 yy
#define f first
#define s second
#define ll long long
#define vi vector<ll>
#define pii pair<ll, ll>
#define debug if(printDebug)
#define noDebug if(!printDebug)
using namespace std;
template<class T>
using v=vector<T>;   
bool printDebug=false;
vi vec, sum;
set<ll> st;
ll binary(ll l, ll r, ll val){
	ll pos=-1;
	while(l<=r){
		ll mid=(l+r)/2;
		if(vec[mid]<=val){
			l=mid+1;
		}
		else{
			r=mid-1;
			pos=mid;
		}
	}
	return pos;
}
void generate(ll l0, ll r1){
	if(l0<0 || r1<0) return;
	ll actSum=sum[r1]-(l0-1<0 ? 0 : sum[l0-1]);
	st.insert(actSum);
	ll mid=(vec[l0]+vec[r1])/2;
	ll r0=binary(l0, r1, mid);
	ll l1=r0-1;
	if(l0!=r1){
		generate(l0, l1);
		generate(r0, r1);
	}
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    ll cases;
    cin >> cases;
    while(cases--){
    	ll n, q;
    	cin >> n >> q;
    	vec=vi(n);
    	sum=vi(n);
    	st=set<ll>();
    	for(ll &x : vec) cin >> x;
    	sort(vec.begin(), vec.end());
    	sum[0]=vec[0];
    	for(ll i=1; i<n; i++){
    		sum[i]=vec[i]+sum[i-1];
    	}
    	generate(0, n-1);
    	ll actQ;
    	for(ll i=0; i<q; i++){
    		cin >> actQ;
    		cout << (st.count(actQ) ? "Yes" : "No") << "\n";
    	}
    }
    return 0;
}
