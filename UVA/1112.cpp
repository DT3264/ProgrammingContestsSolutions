#include <bits/stdc++.h>
using namespace std;
struct Connection{
	int ind;
	int cost;
};
struct Pos{
	int ind;
	int time;
	int operator()(const Pos &p1, const Pos &p2){
		return p1.time<p2.time;
	}
};
void solve(){
	int time[101];
	memset(time, -1, sizeof(time));
	vector<Connection> conn[101];
	int n, e, t, m;
	int u, v, c;
	int i;
	scanf("%d%d%d%d", &n, &e, &t, &m);
	for(i=0; i<m; i++){
		scanf("%d%d%d", &u, &v, &c);
		conn[v].push_back({u, c});
	}
	int canEscape=1;
	time[e]=t;
	priority_queue<Pos, vector<Pos>, Pos> pQ;
	pQ.push({e, t});
	Pos aPos;
	while(!pQ.empty()){
		aPos=pQ.top();
		pQ.pop();
		//printf("On %d with %d\n", aPos.ind, aPos.time);
		for(Connection x : conn[aPos.ind]){
			int nT=aPos.time-x.cost;
			if(nT>=0){
				if(time[x.ind]==-1 or (time)){
					if(time[x.ind]==-1){
						canEscape++;
					}
					time[x.ind]=nT;
					//printf("gong to %d with %d\n", x.ind, nT);
					pQ.push({x.ind, nT});
				}
			}
		}
	}
	printf("%d\n", canEscape);
}
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int cases;
	scanf("%d", &cases);
	while(cases--){
		solve();
		if(cases!=0){
			printf("\n");
		}
	}
}
