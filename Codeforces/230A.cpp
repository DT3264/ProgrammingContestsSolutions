#include<stdio.h>
struct dragon{
    int health;
    int bonus;
}dragons[1000];
int main(){
    int myStrength, n, i;
    scanf("%d%d", &myStrength, &n);
    for(i=0; i<n; i++){
        scanf("%d%d", &dragons[i].health, &dragons[i].bonus);
    }
    int remainDragons = n;
    while(remainDragons>0){
        int bestChoice = -1e9;
        int posBestChoice=-1;
        for(i=0; i<n; i++){
            if(dragons[i].health==-1) continue;
            else if(dragons[i].health<myStrength){
                int actualStrength=myStrength;
                actualStrength -= dragons[i].health;
                actualStrength += dragons[i].bonus;
                if(actualStrength>bestChoice){
                    bestChoice=actualStrength;
                    posBestChoice=i;
                }
            }
        }
        if(posBestChoice==-1){
            break;
        }
        else{
            myStrength += dragons[posBestChoice].bonus;
            dragons[posBestChoice].health=-1;
            remainDragons--;
        }
    }
    printf("%s", (remainDragons==0 ? "YES" : "NO"));
    return 0;
}
