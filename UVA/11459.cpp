#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, players, moves, dice, u, v;
    cin >> n;
    while(n--){
        cin >> players >> moves >> dice;
        vector<int> fromTo(101, 0);
        vector<int> playersPos(players, 1);
        for(int i=0; i<moves; i++){
            cin >> u >> v;
            fromTo[u]=v;
        }
        bool reached100=false;
        int actualPlayer=0, actualRound;
        for(int i=0; i<dice; i++){
            cin >> actualRound;
            if(!reached100){
                int actualPos=playersPos[actualPlayer];
                actualPos+=actualRound;
                if(actualPos>100){
                    actualPos=100;
                }
                if(fromTo[actualPos]>0){
                    actualPos=fromTo[actualPos];
                }
                if(actualPos==100){
                    reached100=true;
                }
                playersPos[actualPlayer]=actualPos;
                actualPlayer++;
                if(actualPlayer==players){
                    actualPlayer=0;
                }
            }
        }
        for(int i=0; i<playersPos.size(); i++){
            cout << "Position of player " << i+1 << " is " << playersPos[i] << ".\n";
        }
    }
	return 0;
}
