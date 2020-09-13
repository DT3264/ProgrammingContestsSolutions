
// Problem : B. Kuriyama Mirai's Stones
// Contest : Codeforces - Codeforces Round #248 (Div. 2)
// URL : https://codeforces.com/problemset/problem/433/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define y1 yy
#define f first
#define s second
#define ll long long
#define vi vector<ll>
#define pii pair<int, int>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int n;
    cin >> n;
    vi v1(n), v2(n), s1(n), s2(n);
    for(int i=0; i<n; i++){
    	cin >> v1[i];
    	v2[i]=v1[i];
    }
    sort(v2.begin(), v2.end());
    s1[0]=v1[0];
    s2[0]=v2[0];
    for(int i=1; i<n; i++){
    	s1[i]=s1[i-1]+v1[i];
    	s2[i]=s2[i-1]+v2[i];
    }
    int q, op, l, r;
    cin >> q;
    while(q--){
    	cin >> op >> l >> r;
    	l--;
    	r--;
    	if(op==1){
    		cout << s1[r]-(l-1>=0 ? s1[l-1] : 0) << "\n";
    	}
    	else{
    		cout << s2[r]-(l-1>=0 ? s2[l-1] : 0) << "\n";
    	}
    }
    return 0;
}
