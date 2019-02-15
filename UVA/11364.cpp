#include<iostream>
#include<algorithm>
int main(){
    int cases, cantLot, pLot;
    int minN, maxN;
    scanf("%d", &cases);
    for(int i=0; i<cases; i++){
        minN=1e9;
        maxN=0;
        scanf("%d", &cantLot);
        while(cantLot--){
            scanf("%d", &pLot);
            minN=std::min(minN, pLot);
            maxN=std::max(maxN, pLot);
        }
        printf("%d\n", (maxN-minN)*2);
    }
    return 0;
}

