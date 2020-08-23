
// Problem : C. Good Subarrays
// Contest : Codeforces - Educational Codeforces Round 93 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1398/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define y1 yy
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
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
    	ll n, ans=0;
    	string str;
    	map<ll, ll> mp;
    	cin >> n >> str;
    	vector<ll> vec(n), sum(n, 0);
    	vec[0]=str[0]-'0';
    	sum[0]=vec[0];
    	mp[0]++;
    	for(int i=0; i<n; i++){
    		vec[i]=str[i]-'0';
    		sum[i]=vec[i]+(i==0 ? 0 : sum[i-1]);
    		ans+=mp[sum[i]-(i+1)];
    		mp[sum[i]-(i+1)]++;
    	}
    	cout << ans << "\n";
    }
    return 0;
}
