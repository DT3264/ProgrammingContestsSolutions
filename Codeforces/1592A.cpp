// Problem: A. Gamer Hemose
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.com/contest/1592/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
bool printDebug=false;
using namespace std;
template<class T>
using v=vector<T>;
int main(){
    // printDebug=true;
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	ll n, h;
    	cin >> n >> h;
    	v<int> vec(n);
    	for(auto &x : vec) cin >> x;
    	sort(vec.begin(), vec.end());
    	ll v1=vec[n-1];
    	ll v2=vec[n-2];
    	ll t1=h/(v1+v2);
    	ll rem=h%(v1+v2);
    	t1*=2;
    	if(rem>0) t1++;
    	rem-=v1;
    	if(rem>0) t1++;
    	// cout << "rem: " << rem << "," << (v1+v2) << ",";
    	cout << t1 << '\n';
    }
    return 0;
}
