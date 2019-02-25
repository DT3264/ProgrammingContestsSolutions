#include<stdio.h>
int main(){
    int cases;
    int holes;
    int i, j;
    int y1, y2;
    int actualSum;
    bool goodCase;
    scanf("%d", &cases);
    for(i=0; i<cases; i++){
        goodCase=true;
        scanf("%d", &holes);
        scanf("%d%d", &y1, &y2);
        actualSum=y1-y2;
        for(j=1; j<holes; j++){
            scanf("%d%d", &y1, &y2);
            if(y1-y2!=actualSum){
                goodCase=false;
            }
        }
        printf("%s\n", (goodCase ? "yes" : "no"));
        if(i<cases-1){
            printf("\n");
        }
    }
    return 0;
}
