#include<stdio.h>
int main(){
    int n, k, i, candiesToday, remainCandies=0;
    scanf("%d %d", &n, &k);
    for(i=0; i<n; i++){
        scanf("%d", &candiesToday);
        candiesToday+=remainCandies;
        remainCandies=0;
        if(candiesToday>8){
            remainCandies+=candiesToday-8;
            candiesToday=8;
        }
        k-=candiesToday;
        if(k<=0){
            printf("%d\n", i+1);
            return 0;
        }
    }
    printf("%d\n", -1);
    return 0;
}
