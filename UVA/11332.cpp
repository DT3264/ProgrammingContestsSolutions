#include<stdio.h>
int main(){
    int i, strPos;
    int total, tmpTotal;
    while(scanf("%d", &total) && total!=0){
        while(total>9){
            tmpTotal=0;
            while(total>0){
                tmpTotal+=total%10;
                total/=10;
            }
            total=tmpTotal;
        }
        printf("%d\n", total);
    }
    return 0;
}
