#include<stdio.h>
struct point{
    int x;
    int y;
}obelisk[1000], clue[1000], result;
int n;
bool used[1000], found;

void findT(int pInd, point base){
    if(found) return;
    if(pInd==n){
        result=base;
        found=true;
        return;
    }
    for(int i=0; i<n; i++){
        if(used[i]) continue;
        if(obelisk[pInd].x+clue[i].x == base.x && obelisk[pInd].y+clue[i].y == base.y){
            used[i]=true;
            findT(pInd+1, base);
            used[i]=false;
        }
    }
}

int main(){
    int i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d%d", &obelisk[i].x, &obelisk[i].y);
    }
    for(i=0; i<n; i++){
        scanf("%d%d", &clue[i].x, &clue[i].y);
    }
    point base;
    for(i=0; i<n; i++){
        base.x=obelisk[0].x+clue[i].x;
        base.y=obelisk[0].y+clue[i].y;
        used[i]=true;
        findT(1, base);
        used[i]=false;
    }
    printf("%d %d", result.x, result.y);
    return 0;
}
