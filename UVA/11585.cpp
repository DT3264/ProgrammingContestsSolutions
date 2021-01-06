
// Problem : 11585 - Nurikabe
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2632
// Memory Limit : 32 MB
// Time Limit : 1000 ms
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
int n, m, c;
v<v<char>> grid;
int dX[4]={-1, 1, 0, 0};
int dY[4]={0, 0, -1, 1};
int dX2[8]={-1, -1, -1, 0, 0, 1, 1, 1};
int dY2[8]={-1, 0, 1, -1, 1, -1, 0, 1};
bool isValid(int x, int y){
	return x>=0 && x<n && y>=0 && y<m;
}
bool allBlack(int x, int y){
	return grid[x][y]=='#' && 
	grid[x][y+1]=='#' &&
	grid[x+1][y]=='#' &&
	grid[x+1][y+1]=='#';
}
bool bfsWhite(int x, int y, int count){
	queue<pii> q;
	if(grid[x][y]=='.'){
		q.push({x, y});
		grid[x][y]='*';
		count--;
	}
	while(!q.empty()){
		auto act=q.front();
		q.pop();
		int aX=act.f;
		int aY=act.s;
		for(int i=0; i<4; i++){
			int nX=aX+dX[i];
			int nY=aY+dY[i];
			if(isValid(nX, nY) && grid[nX][nY]=='.'){
				q.push({nX, nY});
				grid[nX][nY]='*';
				count--;
			}
		}
	}
	return count==0;
}
int bfsBlack(int x, int y){
	int blackSum=0;
	queue<pii> q;
	q.push({x, y});
	grid[x][y]='b';
	blackSum++;
	while(!q.empty()){
		auto act=q.front();
		q.pop();
		int aX=act.f;
		int aY=act.s;
		for(int i=0; i<4; i++){
			int nX=aX+dX[i];
			int nY=aY+dY[i];
			if(isValid(nX, nY) && grid[nX][nY]=='#'){
				q.push({nX, nY});
				grid[nX][nY]='b';
				blackSum++;
			}
		}
	}
	return blackSum;
}
void bfsBorder(int x, int y){
	queue<pii> q;
	q.push({x, y});
	grid[x][y]='.';
	while(!q.empty()){
		auto act=q.front();
		q.pop();
		int aX=act.f;
		int aY=act.s;
		for(int i=0; i<8; i++){
			int nX=aX+dX2[i];
			int nY=aY+dY2[i];
			if(isValid(nX, nY) && grid[nX][nY]=='*'){
				q.push({nX, nY});
				grid[nX][nY]='.';
			}
		}
	}
}
bool canSolve(){
	int whiteCount=0;
	int blackCount=0;
	int whiteSum=0;
	int blackSum=0;
	v<pair<pii, int>> starts(c);
	for(auto &p : starts){
		cin >> p.f.f >> p.f.s >> p.s;
		whiteSum+=p.s;
	}
	grid=v<v<char>>(n, v<char>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){		
			cin >> grid[i][j];
			if(grid[i][j]=='.') whiteCount++;
			if(grid[i][j]=='#') blackCount++;
		}
	}
	for(int i=0; i<n-1; i++){
		for(int j=0; j<m-1; j++){
			if(allBlack(i, j)) return false;
		}
	}
	if(whiteCount!=whiteSum) return false;
	for(auto &p : starts){
		if(!bfsWhite(p.f.f, p.f.s, p.s)) return false;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grid[i][j]=='#'){
				blackSum=bfsBlack(i, j);
				i=n;
				j=m;
			}
		}
	}
	if(blackCount!=blackSum) return false;
	///bfs de los 4 extremos, se mueve en las 8 direcciones (agregar dX2)
	// transformar todos los * en .
	// y comprobar si todos son .
	//si son *, no se pudo alcanzar de ningún extremo y false
	for(int i=0; i<n; i++){
		if(grid[i][0]=='*') bfsBorder(i, 0);
		if(grid[i][m-1]=='*') bfsBorder(i, m-1);
	}
	for(int j=0; j<m; j++){
		if(grid[0][j]=='*') bfsBorder(0, j);
		if(grid[n-1][j]=='*') bfsBorder(n-1, j);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grid[i][j]=='*') return false;
		}
	}
	return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cases;
    cin >> cases;
    while(cases--){
    	cin >> n >> m >> c;
    	cout << (canSolve() ? "solved" : "not solved") << "\n";
    	/*for(auto &row : grid){
    		for(auto &col : row) cout << col;
    		cout << "\n";
    	}*/
    }
    return 0;
}
