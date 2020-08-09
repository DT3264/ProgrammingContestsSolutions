
// Problem : C. Boats Competition
// Contest : Codeforces - Codeforces Round #661 (Div. 3)
// URL : https://codeforces.com/contest/1399/problem/C
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
    	int n, x;
    	cin >> n;
    	map<int, int> freq;
    	for(int i=0; i<n; i++){
    		cin >> x;
    		freq[x]++;
    	}
    	int ans=0;
    	for(int i=2; i<=100; i++){
    		debug cout << "For " << i << "\n";
    		int lAns=0;
    		for(int j=i%2==0 ? i/2 : (i/2)+1; j<=50; j++){
    			if(j==i/2){
    				debug cout << "Can add " << freq[j]/2 << " of " << j << "\n";
    				lAns+=freq[j]/2;
    			}
    			else{
    				if(min(freq[j], freq[i-j])>0)
    				debug cout << "Can add " << freq[j] << " vs " << freq[i-j] << "\n";
    				lAns+=min(freq[j], freq[i-j]);
    			}
    		}
    		debug cout << "LAns: " << lAns << "\n";
    		ans=max(ans, lAns);
    	}
    	debug cout << "Ans:\n";
    	cout << ans << "\n";
    }
    return 0;
}
