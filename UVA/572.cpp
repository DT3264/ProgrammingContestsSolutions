
// Problem : 572 - Oil Deposits
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=513
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
int dX[8]={-1, -1, -1, 0, 0, 1, 1, 1};
int dY[8]={-1, 0, 1, -1, 1, -1, 0, 1};
int n, m;
v<v<char>> grid;
bool isValid(int x, int y){
	return x>=0 && x<n && y>=0 && y<m && grid[x][y]=='@';
}
void expand(int x, int y){
	queue<pii> q;
	q.push({x, y});
	grid[x][y]='.';
	while(!q.empty()){
		auto act=q.front();
		q.pop();
		int aX=act.f;
		int aY=act.s;
		for(int i=0; i<8; i++){
			int nX=aX+dX[i];
			int nY=aY+dY[i];
			if(isValid(nX, nY)){
				q.push({nX, nY});
				grid[nX][nY]='.';
			}
		}
	}
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n >> m){
    	if(n==0 && m==0) break;
    	grid=v<v<char>>(n, v<char>(m));
    	for(auto &row : grid){
    		for(auto &col : row) cin >> col;
    	}
    	int ans=0;
    	for(int i=0; i<n; i++){
    		for(int j=0; j<m; j++){
    			if(grid[i][j]=='@'){
    				expand(i, j);
    				ans++;
    			}
    		}
    	}
    	cout << ans << "\n";
    }
    return 0;
}
