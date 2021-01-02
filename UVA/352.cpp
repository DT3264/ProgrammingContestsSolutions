
// Problem : 352 - The Seasonal War
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=288
// Memory Limit : 32 MB
// Time Limit : 3000 ms
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
int n;
v<v<char>> grid;
int dX[8]={-1, -1, -1,  0, 0, 1,  1, 1};
int dY[8]={-1,  0,  1, -1, 1, -1, 0, 1};
bool isValid(int x, int y){
	return x>=0 && x<n && y>=0 && y<n && grid[nX][nY]=='1';
}
void expand(int x, int y){
	queue<pii> q;
	q.push({x, y});
	grid[x][y]='*';
	while(!q.empty()){
		auto act=q.front();
		q.pop();
		int actX=act.f;
		int actY=act.s;
		for(int i=0; i<8; i++){
			int nX=actX+dX[i];
			int nY=actY+dY[i];
			if(isValid(nX, nY)){
				q.push({nX, nY});
				grid[nX][nY]='*';
			}
		}
	}
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    int actCase=1;
    while(cin >> n){
    	grid=v<v<char>>(n, v<char>(n));
    	for(int i=0; i<n; i++){
    		for(int j=0; j<n; j++){
    			cin >> grid[i][j];
    		}
    	}
    	int ans=0;
    	for(int i=0; i<n; i++){
    		for(int j=0; j<n; j++){
    			if(grid[i][j]=='1'){
    				expand(i, j);
    				ans++;
    			}
    		}
    	}
    	cout << "Image number " << actCase++ << " contains " << ans << " war eagles.\n";
    }
    return 0;
}
