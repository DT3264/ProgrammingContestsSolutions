#include <bits/stdc++.h>
using namespace std;
struct Pos{
    int elevator;
    int floor;
    int time;
    int operator()(const Pos &p1, const Pos &p2){
        return p1.time>p2.time;
    }
};
void solve(int n, int t){
    int i, j;
    int elevatorTime[5];
    bool canTo[5][101];
    int minTime[5][101];
    memset(canTo, false, sizeof(canTo));
    memset(minTime, -1, sizeof(minTime));
    for(i=0; i<n; i++){
        cin >> elevatorTime[i];
    }
    for(i=0; i<n; i++){
        string s;
        getline(cin, s);
        if(s.length()==0){
            getline(cin, s);
        }
        stringstream ss=stringstream(s);
        int nextFloor;
        while(ss>>nextFloor){
            canTo[i][nextFloor]=1;
        }
    }
    priority_queue<Pos, vector<Pos>, Pos> pQ;
    for(i=0; i<n; i++){
        if(canTo[i][0]){
            pQ.push({i, 0, 0});
            minTime[i][0]=0;
        }
    }
    Pos aPos;
    while(!pQ.empty()){
        aPos=pQ.top();
        pQ.pop();
        //printf("En elevador: %d y piso: %d con %d\n", aPos.elevator, aPos.floor, aPos.time);
        for(i=0; i<n; i++){
            if(i==aPos.elevator) continue;
            int newTime=aPos.time+60;
            ///Si puedo llegar más rápido a ese piso
            if(canTo[i][aPos.floor] && (minTime[i][aPos.floor]==-1 || newTime<minTime[i][aPos.floor])){
                //printf("Pasando a elevador %d con %d vs %d\n", i, newTime, minTime[i][aPos.floor]);
                minTime[i][aPos.floor]=newTime;
                pQ.push({i, aPos.floor, newTime});
            }
        }
        ///Busco el siguiente piso al que puedo llegar a arriba
        for(j=aPos.floor+1; j<=100; j++){
            if(canTo[aPos.elevator][j]){
                ///Mi tiempo actual + moverme entre piso actual al j
                int newTime=aPos.time+(j-aPos.floor)*elevatorTime[aPos.elevator];
                //printf("Pasando al piso: %d con %d vs %d?\n", j, newTime, minTime[aPos.elevator][j]);
                if(minTime[aPos.elevator][j]==-1 || newTime<minTime[aPos.elevator][j]){
                    minTime[aPos.elevator][j]=newTime;
                    pQ.push({aPos.elevator, j, newTime});
                }
                break;
            }
        }
        ///Busco el piso previo para abajo
        for(j=aPos.floor-1; j>=0; j--){
            if(canTo[aPos.elevator][j]){
                ///Mi tiempo actual + moverme entre piso actual al j
                int newTime=aPos.time+(aPos.floor-j)*elevatorTime[aPos.elevator];
                //printf("Pasando al piso: %d con %d vs %d?\n", j, newTime, minTime[aPos.elevator][j]);
                if(minTime[aPos.elevator][j]==-1  || newTime<minTime[aPos.elevator][j]){
                    minTime[aPos.elevator][j]=newTime;
                    pQ.push({aPos.elevator, j, newTime});
                }
                break;
            }
        }
        //system("pause");
    }
    int ans=999999;
    for(i=0; i<n; i++){
        if(minTime[i][t]!=-1){
            ans=min(ans, minTime[i][t]);
        }
    }
    if(ans!=999999) printf("%d\n", ans);
    else printf("IMPOSSIBLE\n");
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, t;
	while(cin >> n >> t){
		solve(n, t);
	}
}
