
// Problem : 11906 - Knight in a War Grid
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3057
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
int even, odd;
int n, m, distX, distY;
bool hasWater[101][101];
bool visited[101][101];
int dX[4]={-1, -1, 1, 1};
int dY[4]={-1, 1, -1, 1};
bool canGoTo(int x, int y){
	if(x<0 || x>=n || y<0 || y>=m) return false;
	if(hasWater[x][y]) return false;
	return true;
}
struct Pos{
	int x;
	int y;
};
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    int cases;
    cin >> cases;
    for(int actCase=1; actCase<=cases; actCase++){
    	int w;
    	cin >> n >> m >> distX >> distY >> w;
    	int x, y;
    	memset(hasWater, 0, sizeof(hasWater));
    	memset(visited, 0, sizeof(visited));
    	for(int i=0; i<w; i++){
    		cin >> x >> y;
    		hasWater[x][y]=1;
    	}
    	even=0;
    	odd=0;
    	queue<Pos> q;
    	q.push({0, 0});
    	visited[0][0]=1;
    	while(!q.empty()){
    		auto aPos=q.front();
    		q.pop();
    		int x=aPos.x;
    		int y=aPos.y;
    		set<pair<int, int>> s;
    		for(int i=0; i<4; i++){
				int nX=x+(distX*dX[i]);
				int nY=y+(distY*dY[i]);
				if(canGoTo(nX, nY)){
					s.insert({nX, nY});
					if(!visited[nX][nY]){
						visited[nX][nY]=1;
						q.push({nX, nY});
					}
				}
				nX=x+(distY*dX[i]);
				nY=y+(distX*dY[i]);
				if(canGoTo(nX, nY)){
					s.insert({nX, nY});
					if(!visited[nX][nY]){
						visited[nX][nY]=1;
						q.push({nX, nY});
					}
				}
			}
			if(s.size()%2==0) even++;
			else odd++;
    	}
    	cout << "Case " << actCase << ": " << even << " " << odd << "\n";
    }
    return 0;
}
