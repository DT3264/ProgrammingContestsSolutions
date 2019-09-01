#include<stdio.h>
#include<algorithm>
#define abs std::abs
int main(){
    int n, l;
    int total=0, actTotal;
    int minDif=1e9;
    int ans=0;
    scanf("%d%d", &n, &l);
    for(int i=0; i<n; i++){
        total+=l+i;
    }
    //printf("Starting with %d\n", total);
    for(int i=0; i<n; i++){
        actTotal=total-(l+i);
        //printf("posible: %d\n", actTotal);
        if(abs(abs(total)-abs(actTotal))<minDif){
            minDif=abs(abs(total)-abs(actTotal));
            //printf("diff of %d\n", minDif);
            ans=actTotal;
        }
    }
    printf("%d\n", ans);
    return 0;
}
