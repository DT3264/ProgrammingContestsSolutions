
// Problem : 12488 - Start Grid
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=3932&mosmsg=Submission+received+with+ID+25517681
// Memory Limit : 32 MB
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
    int n;
    while(cin >> n){
    	vector<int> v1(n), v2(n);
    	map<int, int> index;
    	for(int i=0; i<n; i++){
    		cin >> v1[i];
    		index[v1[i]]=i;
    	}
    	for(int &x : v2) cin >> x;
    	int ans=0;
    	for(int i=0; i<n; i++){
    		int startPos;
    		for(int j=0; j<n; j++){
    			if(v2[j]==v1[i]) {
    				startPos=j+1; 
    				break;
    			}
    		}
    		for(int j=startPos; j<n; j++){
    			if(index[v2[j]]<i) ans++;
    		}
    	}
    	cout << ans << "\n";
    }
    return 0;
}
