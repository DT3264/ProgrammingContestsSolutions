#include <bits/stdc++.h>
using namespace std;
struct Connection{
	int ind;
	int delay;
};
struct Pos{
	int ind;
	int time;
	int operator()(const Pos &p1, const Pos &p2){
		return p1.time>p2.time;
	}
};
int actualCase=1;
void solve(){
	int i;
	int u, v, d;
	int n, m, S, T;
	int minDist[20000];
	memset(minDist, -1, sizeof(minDist));
	vector<Connection> conn[20000];
	scanf("%d%d%d%d", &n, &m, &S, &T);
	for(i=0; i<m; i++){
		scanf("%d%d%d", &u, &v, &d);
		conn[u].push_back({v, d});
		conn[v].push_back({u, d});
	}
	priority_queue<Pos, vector<Pos>, Pos> pQ;
	pQ.push({S, 0});
	Pos aPos;
	while(!pQ.empty()){
		aPos=pQ.top();
		pQ.pop();
		for(Connection x : conn[aPos.ind]){
			int nT=aPos.time+x.delay;
			if(minDist[x.ind]==-1){
				//Si no he pasado
				minDist[x.ind]=nT;
				pQ.push({x.ind, nT});
			}
			else if(minDist[x.ind]>nT){
				//Si tengo algo mejor
				minDist[x.ind]=nT;
				pQ.push({x.ind, nT});
			}
		}
	}
	if(minDist[T]!=-1){
		printf("Case #%d: %d\n", actualCase, minDist[T]);
	}
	else{
		printf("Case #%d: unreachable\n", actualCase);
	}
}
int main(){
	int cases;
	scanf("%d", &cases);
	while(actualCase<=cases){
		solve();
		actualCase++;
	}
}
