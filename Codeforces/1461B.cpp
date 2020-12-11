// Problem : B. Find the Spruce
// Contest : Codeforces - Codeforces Round #689 (Div. 2, based on Zed Code Competition)
// URL : https://codeforces.com/contest/1461/problem/B
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
#define noDebug if(!printDebug)
using namespace std;
template<class T>
using v=vector<T>;   
bool printDebug=false;
int n, m;
char grid[500][500];
int countL[500][500];
int countR[500][500];
bool cuenta(int i, int j, int sum){
	if(i>=n) return false;
	return countL[i][j]>=sum && countR[i][j]>=sum;
}
void mark(int row, int l, int r){
	int countLocal=0;
	for(int i=l; i<=r; i++){
		countL[row][i]=countLocal++;
	}
	countLocal=0;
	for(int i=r; i>=l; i--){
		countR[row][i]=countLocal++;
	}
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    int cases;
    cin >> cases;
    while(cases--){
    	cin >> n >> m;
    	int ans=0;
    	for(int i=0; i<n; i++){
    		for(int j=0; j<m; j++){
    			cin >> grid[i][j];
    			countL[i][j]=0;
    			countR[i][j]=0;
    		}
    		int start=-1;
    		for(int j=0; j<m; j++){
    			if(grid[i][j]=='*'){
    				if(start==-1) start=j;
    			}
    			if(grid[i][j]=='.' && start!=-1){
    				mark(i, start, j-1);
    				start=-1;
    			}
    		}
    		if(start!=-1){
    			mark(i, start, m-1);
    			start=-1;
    		}
    	}
    	for(int i=0; i<n; i++){
    		for(int j=0; j<m; j++){
    			if(grid[i][j]=='*'){
    				int row=i;
    				int pad=0;
    				while(cuenta(row, j, pad)){
    					row++;
    					pad++;
    					ans++;
    				}
    			}
    			grid[i][j]='.';
    		}
    	}
    	cout << ans << "\n";
    }
    return 0;
}