
// Problem : B. Stairs
// Contest : Codeforces - Codeforces Round #671 (Div. 2)
// URL : https://codeforces.com/contest/1419/problem/B
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
vector<ll> blocks;
void generateBlocks(){
	ll actSize=1;
    ll actBlocks=1;
    ll nextBlocks=1;
    blocks.push_back(actSize);
    while(nextBlocks<1e18){
    	nextBlocks=actBlocks+(actSize*2*2)+actBlocks;
    	actSize=actSize*2*2;
    	actBlocks=nextBlocks;
    	blocks.push_back(nextBlocks);
    }
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    generateBlocks();
    int cases;
    cin >> cases;
    while(cases--){
    	ll n;
    	cin >> n;
    	int ans=0;
    	for(ll &x : blocks){
    		if(n-x>=0){
    			n-=x;
    			ans++;
    		}
    	}
    	cout << ans << "\n";
    }
    return 0;
}
