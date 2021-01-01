
// Problem : 11561 - Getting Gold
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2597
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
#define noDebug if(!printDebug)
using namespace std;
template<class T>
using v=vector<T>;   
bool printDebug=false;
struct Pos{
	int x;
	int y;
};
int n, m;
int dX[4]={0, 0, -1, 1};
int dY[4]={-1, 1, 0, 0};
v<v<char>> grid;
bool isValid(int x, int y){
	return x>=0 && x<n && y>=0 && y<m && (grid[x][y]=='.' || grid[x][y]=='G');
}
bool isTrapFree(int x, int y){
	for(int i=0; i<4; i++){
		int nX=x+dX[i];
		int nY=y+dY[i];
		if(grid[nX][nY]=='T') return false;
	}
	return true;
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    while(cin >> m >> n){
    	grid=v<v<char>>(n, v<char>(m));
    	queue<Pos> q;
    	for(int i=0; i<n; i++){
    		for(int j=0; j<m; j++){
    			cin >> grid[i][j];
    			if(grid[i][j]=='P') q.push({i, j});
    		}
    	}
    	int ans=0;
    	while(!q.empty()){
    		auto act=q.front();
    		q.pop();
    		int x=act.x;
    		int y=act.y;
    		if(!isTrapFree(x, y)) continue;
    		for(int i=0; i<4; i++){
    			int nX=x+dX[i];
    			int nY=y+dY[i];
    			if(isValid(nX, nY)){
    				q.push({nX, nY});
		    		if(grid[nX][nY]=='G') ans++;
		    		grid[nX][nY]='*';	
    			}
    		}
    	}
    	cout << ans << "\n";
    }
    return 0;
}
