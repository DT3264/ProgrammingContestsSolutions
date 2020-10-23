// Problem : C. Dominant Piranha
// Contest : Codeforces - Codeforces Round #677 (Div. 3)
// URL : https://codeforces.com/contest/1433/problem/C
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
    int cases;
    cin >> cases;
    while(cases--){
    	int n;
    	cin >> n;
    	vector<int> vec(n);
    	int biggest=0;
    	for(int &x : vec){
    		cin >> x;
    		biggest=max(biggest, x);
    	}
    	int ans=-1;
		for(int i=0; i<n && ans==-1; i++){
			if(i-1>=0 && vec[i]==biggest && vec[i-1]<vec[i]) ans=i;
			if(i+1<n && vec[i]==biggest && vec[i+1]<vec[i]) ans=i;
		}
		cout << (ans!=-1 ? ans+1 : ans)<< "\n";
	}
    return 0;
}