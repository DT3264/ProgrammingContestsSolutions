#include<stdio.h>
#include<string.h>
bool listA[150][150];
int bestTime[150];
int canExit=0;
int n, e, t, i;
void submarino(int zone, int time){
    if(time>=t) return;
    if(bestTime[zone]==-1 || bestTime[zone]>time){
        if(bestTime[zone]==-1) canExit++;///Aún no ha llegado ahí
        bestTime[zone]=time;
    }
    for(int i=1; i<n; i++){
        if(listA[zone][i]){///Se puede llegar
            if(time+1<t && (bestTime[i]==-1 || bestTime[i]>time+1)){///Menor que el tiempo / No se ha visitado o hay algo mejor
                submarino(i, time+1);
            }
        }
    }
}

int main(){
    memset(bestTime, -1, sizeof(bestTime));
    scanf("%d%d%d", &n, &e, &t);
    int x, y;
    for(i=0; i<e; i++){
        scanf("%d%d", &x, &y);
        listA[x][y]=1;
        listA[y][x]=1;
    }
    for(i=1; i<n; i++){
        if(listA[n][i]){
            if(t>1)
            submarino(i, 1);
        }
    }

    printf("%d", canExit);
    return 0;
}