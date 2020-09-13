
// Problem : B. Ilya and Queries
// Contest : Codeforces - Codeforces Round #186 (Div. 2)
// URL : https://codeforces.com/problemset/problem/313/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define y1 yy
#define f first
#define s second
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    string str;
    cin >> str;
    vector<int> sum(str.size(), 0);
    for(int i=1; i<str.size(); i++){
    	sum[i]=sum[i-1];
    	sum[i]+=str[i]==str[i-1];
    }
    int q, l, r;
    cin >> q;
    while(q--){
    	cin >> l >> r;
    	l--;
    	r--;
    	cout << sum[r]-sum[l] << "\n";
    }
    return 0;
}
