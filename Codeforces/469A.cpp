#include<stdio.h>
bool level[110];
int main (){
    int n, x, y, i, t;
    scanf("%d", &n);
    scanf("%d", &x);
    for(i=0; i<x; i++){
        scanf("%d", &t);
        level[t-1]=true;
    }
    scanf("%d", &y);
    for(i=0; i<y; i++){
        scanf("%d", &t);
        level[t-1]=true;
    }
    bool canWin = true;
    for(i=0; i<n && canWin; i++){
        if(!level[i]) canWin=false;
    }
    printf(canWin ? "I become the guy." : "Oh, my keyboard!");
    return 0;
}
