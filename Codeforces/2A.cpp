#include<stdio.h>
#include<string.h>
struct player{
    char name[34];
    int points;
} rounds[1000], players[1000], results[1000], actualPlayer;
int cantPlayers, cantResults, maxN=-(1e8);
int n;
bool found;

int addScore(){
    for(int i=0; i<cantPlayers; i++){
        if(strcmp(players[i].name, actualPlayer.name)==0){
            players[i].points+=actualPlayer.points;
            return i;
        }
    }
    players[cantPlayers++]=actualPlayer;
    return cantPlayers-1;
}

void searchWinner(){
    for(int i=0; i<cantPlayers; i++){
        for(int j=0; j<cantResults; j++){
            ///Si nombres iguales
            ///Puntaje mayor o igual al mejor
            ///Y resultado final al mejor
            if(strcmp(players[i].name, results[j].name)==0){
                if(players[i].points>=maxN &&
                    results[j].points==maxN){
                    printf("%s", players[i].name);
                    found=true;
                }
            }
        }
    }
}

int main(){
    int i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%s %d", rounds[i].name, &rounds[i].points);
        actualPlayer=rounds[i];
        addScore();
    }
    memcpy(results, players, sizeof(players));
    memset(players, 0, sizeof(players));
    cantResults=cantPlayers;
    cantPlayers=0;
    for(i=0; i<cantResults; i++){
        if(results[i].points>maxN){
           maxN=results[i].points;
        }
    }
    for(i=0; i<n && !found; i++){
        actualPlayer=rounds[i];
        addScore();
        searchWinner();
    }
    return 0;
}
