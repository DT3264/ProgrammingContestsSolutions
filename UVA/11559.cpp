#include<stdio.h>
#include<algorithm>
int main (){
    int n, b, h, w;
    int price, beds;
    int result;
    int i, j;
    while(scanf("%d%d%d%d", &n, &b, &h, &w)!=EOF){
        result=-1;
        for(i=0; i<h; i++){
            scanf("%d", &price);
            for(j=0; j<w; j++){
                scanf("%d", &beds);
                if(beds>=n && price*n<=b){
                    if(result==-1){
                        result=price*n;
                    }
                    else{
                        result=std::min(result, price*n);
                    }
                }
            }
        }
        if(result!=-1){
            printf("%d\n", result);
        }
        else{
            printf("stay home\n");
        }
    }
    return 0;
}
