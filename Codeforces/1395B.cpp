
// Problem : B. Boboniu Plays Chess
// Contest : Codeforces - Codeforces Round #664 (Div. 2)
// URL : https://codeforces.com/contest/1395/problem/B
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define si set<int>
#define y1 yy
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
int n, m;
int visited[101][101];
pii getNext(int x, int y){
	//Para abajo
	for(int i=x+1; i<=n; i++){
		if(!visited[i][y]) return {i, y};
	}
	//Para arriba
	for(int i=x-1; i>0; i--){
		if(!visited[i][y]) return {i, y};
	}
	//Para izquierda
	for(int i=y-1; i>0; i--){
		if(!visited[x][i]) return {x, i};
	}
	//Para derecha
	for(int i=y+1; i<=m; i++){
		if(!visited[x][i]) return {x, i};
	}
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int actX, actY;
    int vis=1;
    cin >> n >> m >> actX >> actY;
    cout << actX << " " << actY << "\n";
    pii nextP;
    while(vis<n*m){
    	visited[actX][actY]=1;
    	nextP=getNext(actX, actY);
    	actX=nextP.f;
    	actY=nextP.s;
    	cout << actX << " " << actY << "\n";
    	vis++;
    }
    return 0;
}
