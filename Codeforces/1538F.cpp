
// Problem : F. Interesting Function
// Contest : Codeforces - Codeforces Round #725 (Div. 3)
// URL : https://codeforces.com/contest/1538/problem/F
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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	int n, m;
    	cin >> n >> m;
    	string sN=to_string(n);
    	string sM=to_string(m);
    	for(int i=sN.length(); i<10; i++) sN='0'+sN;
    	for(int i=sM.length(); i<10; i++) sM='0'+sM;
    	ll ans=0;
    	for(int i=1; i<=10; i++){
    		ll v1=stoll(sN.substr(0, i));
    		ll v2=stoll(sM.substr(0, i));
    		ans+=v2-v1;
    	}
    	cout << ans << "\n";
    }
    return 0;
}
