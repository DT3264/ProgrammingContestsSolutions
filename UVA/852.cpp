
// Problem : 852 - Deciding victory in Go
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=793
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
v<string> grid(9);
int dX[4]={-1, 1, 0, 0};
int dY[4]={0, 0, -1, 1};
bool isValid(int x, int y){
	return x>=0 && x<9 && y>=0 && y<9;
}
int expand(int x, int y){
	queue<pii> q;
	q.push({x, y});
	grid[x][y]='*';
	int white=0;
	int black=0;
	int score=1;
	while(!q.empty()){
		auto act=q.front();
		q.pop();
		int aX=act.f;
		int aY=act.s;
		for(int i=0; i<4; i++){
			int nX=aX+dX[i];
			int nY=aY+dY[i];
			if(isValid(nX, nY)){
				if(grid[nX][nY]=='.'){
					grid[nX][nY]='*';
					score++;
					q.push({nX, nY});
				}
				else if(grid[nX][nY]=='X') black++;
				else if(grid[nX][nY]=='O') white++;
			}
		}
	}
	if(black>0 && white==0) return score;
	else if(black==0 && white>0) return -score;
	else return 0; 
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cases;
    cin >> cases;
    while(cases--){
    	for(int i=0; i<9; i++){
    		cin >> grid[i];
    	}
    	int white=0;
    	int black=0;
    	for(int i=0; i<9; i++){
    		for(int j=0; j<9; j++){
    			if(grid[i][j]=='O') white++;
    			else if(grid[i][j]=='X') black++;
    			else if(grid[i][j]=='.'){
    				int score=expand(i, j);
    				if(score>0) black+=score;
    				else white-=score;
    			}
    		}
    	}
    	cout << "Black " << black << " White " << white << "\n";
    }
    return 0;
}
