
// Problem : A. Subset Mex
// Contest : Codeforces - Codeforces Round #670 (Div. 2)
// URL : https://codeforces.com/contest/1406/problem/A
// Memory Limit : 512 MB
// Time Limit : 1000 ms
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
int getMinV(vi &vec){
	for(int i=0; i<=101; i++){
		if(vec[i]==0) return i;
		vec[i]--;
	}
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	int n, v;
    	cin >> n;
    	vector<int> vec(101, 0);
    	for(int i=0; i<n; i++){
    		cin >> v;
    		vec[v]++;
    	}
    	int v1=getMinV(vec);
    	int v2=getMinV(vec);
    	cout << v1+v2 << "\n";
    }
    return 0;
}
