
// Problem : 1103 - Ancient Messages
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3544
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
int n, m;
int dX[4]={-1, 1, 0, 0};
int dY[4]={0, 0, -1, 1};
v<string> grid;
v<vi> ids;
int id=1;
map<char, int> ans;
char letterByHoles(int holes){
	if(holes==0) return 'W';
	else if(holes==1) return 'A';
	else if(holes==2) return 'K';
	else if(holes==3) return 'J';
	else if(holes==4) return 'S';
	else /*if(holes==5)*/ return 'D';
}
bool isValid(int x, int y){
	return x>=0 && x<n && y>=0 && y<m;
}
void fillHole(int x, int y){
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
			if(isValid(nX, nY) && grid[nX][nY]=='0'){
				grid[nX][nY]='*';//hole
				q.push({nX, nY});
			}
		}
	}
}
void findHoles(int x, int y){
	int holes=0;
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
			if(isValid(nX, nY) && grid[nX][nY]=='1'){
				grid[nX][nY]='*';//border
				q.push({nX, nY});
			}
			else if(isValid(nX, nY) && grid[nX][nY]=='0'){
				fillHole(nX, nY);
				holes++;
			}
		}
	}
	char letter=letterByHoles(holes);
	ans[letter]++;
}
void fillBackground(int x, int y){
	queue<pii> q;
	q.push({x, y});
	grid[x][y]='b';
	set<int> s;
	while(!q.empty()){
		auto act=q.front();
		q.pop();
		int aX=act.f;
		int aY=act.s;
		for(int i=0; i<4; i++){
			int nX=aX+dX[i];
			int nY=aY+dY[i];
			if(isValid(nX, nY) && grid[nX][nY]=='0'){
				grid[nX][nY]='b';//hole
				q.push({nX, nY});
			}
		}
	}
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int actCase=1;
    while(cin >> n >> m){
    	if(n==0 && m==0) break;
		char in;
		string sIn;
		grid=v<string>(n);
		ids=v<vi>(n, vi(m*4, -1));
		ans.clear();
	    for(int i=0; i<n; i++){
	    	for(int j=0; j<m; j++){
		    	cin >> in;
		    	sIn="";
	    		sIn+=in;//char to str
	    		int num=stoi(sIn, 0, 16);//str to num with base 16
	    		bitset<4> bs(num);//num to binary
	    		grid[i]+=bs.to_string();//binary to str
	    	}
	    }
	    m*=4;
	    for(int i=0; i<n; i++){
	    	if(grid[i][0]=='0') fillBackground(i, 0);
	    	if(grid[i][m-1]=='0') fillBackground(i, m-1);
	    }
	    for(int j=0; j<m; j++){
	    	if(grid[0][j]=='0') fillBackground(0, j);
	    	if(grid[n-1][j]=='0') fillBackground(n-1, j);
	    }
	    for(int i=0; i<n; i++){
	    	for(int j=0; j<m; j++){
	    		if(grid[i][j]=='1') findHoles(i, j);
	    	}
	    }
	    cout << "Case " << actCase++ << ": ";
	    for(auto &p : ans){
	    	for(int i=0; i<p.s; i++) cout << p.f;
	    }
	    cout << "\n";
    }
    return 0;
}
