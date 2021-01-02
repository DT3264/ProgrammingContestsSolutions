
// Problem : 871 - Counting Cells in a Blob
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=812
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
int n;
v<string> grid;
bool isValid(int x, int y){
	return x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]=='1'; 
}
int expand(int x, int y){
	int blobSize=0;
	queue<pii> q;
	q.push({x, y});
	grid[x][y]='0';
	blobSize++;
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
				grid[nX][nY]='0';
				blobSize++;
			}
		}
	}
	return blobSize;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cases;
    cin >> cases;
    cin.ignore();
    string str;
    getline(cin, str);
    while(cases--){
    	grid.clear();
    	while(getline(cin, str) && str!="") grid.push_back(str);
    	int ans=0;
    	for(int i=0; i<grid.size(); i++){
    		for(int j=0; j<grid[0].size(); j++){
    			if(grid[i][j]=='1') ans=max(ans, expand(i, j));
    		}
    	}
    	cout << ans << "\n";
    	cout << (cases>0 ? "\n":"");
    }
    return 0;
}
