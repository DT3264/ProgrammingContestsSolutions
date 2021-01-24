
// Problem : 10116 - Robot Motion
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1057
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
const int INF=-1;
int n, m;
bool isValid(int x, int y){
	return x>=0 && x<n && y>=0 && y<m;
}
pii nextPos(int x, int y, char c){
	if(c=='N') return {x-1, y};
	else if(c=='W') return {x, y-1};
	else if(c=='S') return {x+1, y};
	else if(c=='E') return {x, y+1};
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int s;
    while(cin >> n >> m >> s){
    	if(n+m+s==0) break;
    	v<v<char>> grid(n, v<char>(m));
    	v<vi> colors(n, vi(m, INF));
    	for(auto &row : grid){
    		for(auto &col : row){
    			cin >> col;
    		}
    	}
    	queue<pii> q, loopQ;
    	int steps=0;
    	int loopSteps=-1;
    	q.push({0, s-1});
    	colors[0][s-1]=0;
    	steps++;
    	bool canReachExit=true;
    	//Paint with first color
    	while(!q.empty()){
    		auto act=q.front();
    		q.pop();
    		int aX=act.f;
    		int aY=act.s;
    		int aC=colors[aX][aY];
	    	auto next=nextPos(aX, aY, grid[aX][aY]);
	    	int nX=next.f;
	    	int nY=next.s;
	    	if(isValid(nX, nY)){
	    		if(colors[nX][nY]==INF){
	    			q.push({nX, nY});
	    			//Same color
			    	colors[nX][nY]=aC;
			    	steps++;
		    	}
		    	//Loop reached
		    	else if(colors[nX][nY]==aC){
		    		canReachExit=false;
		    		loopQ.push({nX, nY});
		    		//Paint with second color
		    		colors[nX][nY]=1;
		    		loopSteps=1;
		    	}
		    }
    	}
    	//Paint with second color
    	while(!loopQ.empty()){
    		auto act=loopQ.front();
    		loopQ.pop();
    		int aX=act.f;
    		int aY=act.s;
    		int aC=colors[aX][aY];
	    	auto next=nextPos(aX, aY, grid[aX][aY]);
	    	int nX=next.f;
	    	int nY=next.s;
	    	if(colors[nX][nY]!=aC){
	    		loopQ.push({nX, nY});
	    		//Repaint
	    		colors[nX][nY]=aC;
	    		loopSteps++;
	    	}
    	}
    	if(loopSteps==-1){
    		cout << steps << " step(s) to exit\n";
    	}
    	else{
    		cout << (steps-loopSteps) << " step(s) before a loop of " << loopSteps << " step(s)\n";
    	}
    }
    return 0;
}