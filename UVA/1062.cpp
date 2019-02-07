#include<stdio.h>
#include<string.h>
struct pStack{
    char arr[10000];
    int length=100000;
    int len=0;
    void push(char n){
        arr[len++]=n;
    }
    void pop(){
        len--;
    }
    char top(){
        return arr[len-1];
    }
    bool isEmpty(){
        return len==0;
    }
}piles[1000];
char str[1002];
int main (){
    int i, j, stackCount;
    int bestDiference, bestPos;
    int contCase=1;
    while(scanf("%s", str) && strcmp(str, "end")!=0){
        stackCount=0;
        memset(piles, 0, sizeof(piles));
        for(i=0; str[i]; i++){
            bestDiference=30;
            bestPos=-1;
            for(j=0; j<stackCount; j++){
                if(piles[j].top()>=str[i]){
                    //printf("%c >= %c -> %d\n", piles[j].top(), str[i], piles[j].top()-str[i]);
                    if(piles[j].top()-str[i]<bestDiference){
                        bestDiference=piles[j].top()-str[i];
                        bestPos=j;
                    }
                }
            }
            if(bestPos!=-1){
                //printf("pushing %c in %d\n", str[i], bestPos);
                piles[bestPos].push(str[i]);
            }
            else{
                //printf("pushing %c in new %d\n", str[i], stackCount);
                piles[stackCount++].push(str[i]);
            }
        }
        printf("Case %d: %d\n", contCase++, stackCount);
    }
    return 0;
}
