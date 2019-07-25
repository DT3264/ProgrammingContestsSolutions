#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int q, n;
    scanf("%d", &q);
    while(q--){
        int maxX=100000, maxY=100000, minX=-100000, minY=-100000;
        int aX, aY, canL, canU, canR, canD;
        scanf("%d", &n);
        while(n--){
            scanf("%d%d%d%d%d%d", &aX, &aY, &canL, &canU, &canR, &canD);
            if(!canL){
                minX=max(aX, minX);
            }
            if(!canU){
                maxY=min(aY, maxY);
            }
            if(!canR){
                maxX=min(aX, maxX);
            }
            if(!canD){
                minY=max(aY, minY);
            }
        }
        if(minX<=maxX && minY<=maxY){
            printf("1 %d %d\n", minX, minY);
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}
