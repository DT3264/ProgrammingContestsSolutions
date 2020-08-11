
// Problem : B. Captain Flint and a Long Voyage
// Contest : Codeforces - Codeforces Round #660 (Div. 2)
// URL : https://codeforces.com/contest/1388/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define si set<int>
#define y1 yy
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
    	int n;
    	cin >> n;
    	//If n%4==0, the last useful num can only be 9
    	int eights=(n/4)+1-(n%4==0);
   		for(int i=0; i<n-eights; i++) cout << '9';
   		while(eights-->0) cout << '8';
   		cout << "\n";
    }
    return 0;
}
