
// Problem : 11953 - Battleships
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3104
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
int dX[4]={-1, 1, 0, 0};
int dY[4]={0, 0, -1, 1};
int n;
v<string> grid;
bool isValid(int x, int y){
	return x>=0 && x<n && y>=0 && y<n && (grid[x][y]=='@' || grid[x][y]=='x');
}
void expand(int x, int y){
	queue<pii> q;
	q.push({x, y});
	grid[x][y]='*';
	while(!q.empty()){
		auto act=q.front();
		q.pop();
		int aX=act.f;
		int aY=act.s;
		for(int i=0; i<4; i++){
			int nX=aX+dX[i];
			int nY=aY+dY[i];
			if(isValid(nX, nY)){
				q.push({nX, nY});
				grid[nX][nY]='*';
			}
		}
	}
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cases;
    cin >> cases;
    for(int actCase=1; actCase<=cases; actCase++){
    	cin >> n;
    	grid=v<string>(n);
    	for(auto &row : grid) cin >> row;
    	int ans=0;
    	for(int i=0; i<n; i++){
    		for(int j=0; j<n; j++){
    			if(grid[i][j]=='x'){
    				expand(i, j);
    				ans++;
    			}
    		}
    	}
    	cout << "Case " << actCase << ": " << ans << "\n";
    }
    return 0;
}
