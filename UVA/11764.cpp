#include<stdio.h>
using namespace std;
int main(){
    int n, jumps, actualJump, lastJump;
    int high=0, low=0;
    int i, j;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        high=0;
        low=0;
        scanf("%d", &jumps);
        scanf("%d", &lastJump);
        for(j=0; j<jumps-1; j++){
            scanf("%d", &actualJump);
            if(actualJump>lastJump) high++;
            else if(actualJump<lastJump)low++;
            lastJump = actualJump;
        }
        printf("Case %d: %d %d\n", i+1, high, low);
    }
    return 0;
}
