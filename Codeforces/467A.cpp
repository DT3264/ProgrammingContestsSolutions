#include<stdio.h>
int main(){
    int n, rm, rCap, roomA=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &rm, &rCap);
        if(rm+2<=rCap) roomA++;
    }
    printf("%d\n", roomA);
    return 0;
}
