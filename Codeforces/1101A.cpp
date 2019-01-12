#include<stdio.h>
#include<math.h>
int main(){
    int n;
    int l, r, d, rL, rR;
    scanf("%d", &n);
    while(n--){
        scanf("%d%d%d", &l, &r, &d);
        rL=d*(l/d);
        rR=d*ceil((double)r/(double)d);
        if(rL==l){
            rL-=d;
        }
        if(rR==r){
            rR+=d;
        }
        if(rL<=0){
            ///No questions winner is right
            printf("%d\n", rR);
        }
        else{
            if(l>rL){
                printf("%d\n", d);
            }
            else{
                printf("%d\n", rR);
            }
        }
        //printf("%d %d\n", rL, rR);
    }
    return 0;
}

