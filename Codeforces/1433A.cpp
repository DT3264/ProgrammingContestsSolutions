// Problem : A. Boring Apartments
// Contest : Codeforces - Codeforces Round #677 (Div. 3)
// URL : https://codeforces.com/contest/1433/problem/A
// Memory Limit : 256 MB
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
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	string apt;
    	cin >> apt;
    	int n=apt[0]-'0';
    	int push=apt.size();
    	int ans=(n-1)*10;
    	if(push==1) ans+=1;
    	if(push==2) ans+=3;
    	if(push==3) ans+=6;
    	if(push==4) ans+=10;
    	cout << ans << "\n";
    }
    return 0;
}