
// Problem : 11094 - Continents
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2035
// Memory Limit : 32 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
using namespace std;
template<class T>
using v=vector<T>;
int dX[4]={-1, 1, 0, 0};
int dY[4]={0, 0, -1, 1};
int n, m;
char land;
v<string> grid;
bool isValid(int x, int y){
	return x>=0 && x<n && y>=0 && y<m;
}
void expandMine(int x, int y){
	queue<pii> q;
	q.push({x, y});
	grid[x][y]='m';
	while(!q.empty()){
		auto act=q.front();
		q.pop();
		int aX=act.f;
		int aY=act.s;
		for(int i=0; i<4; i++){
			int nX=aX+dX[i];
			int nY=aY+dY[i];
			if(nY==-1) nY=m-1;
			if(nY==m) nY=0;
			if(isValid(nX, nY) && grid[nX][nY]==land){
				q.push({nX, nY});
				grid[nX][nY]='m';
			}
		}
	}
}
int measure(int x, int y){
	int size=0;
	queue<pii> q;
	q.push({x, y});
	grid[x][y]='*';
	size++;
	while(!q.empty()){
		auto act=q.front();
		q.pop();
		int aX=act.f;
		int aY=act.s;
		for(int i=0; i<4; i++){
			int nX=aX+dX[i];
			int nY=aY+dY[i];
			if(nY==-1) nY=m-1;
			if(nY==m) nY=0;
			if(isValid(nX, nY) && grid[nX][nY]==land){
				q.push({nX, nY});
				grid[nX][nY]='*';
				size++;
			}
		}
	}
	return size;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n >> m){
    	grid=v<string>(n);
    	for(auto &row : grid) cin >> row;
    	int mX, mY;
    	cin >> mX >> mY;
    	land=grid[mX][mY];
    	expandMine(mX, mY);
    	int ans=0;
    	for(int i=0; i<n; i++){
    		for(int j=0; j<m; j++){
    			if(grid[i][j]==land) ans=max(ans, measure(i, j));
    		}
    	}
    	cout << ans << "\n";
    }
    return 0;
}
