#include<stdio.h>
#include<string.h>
int n, t, arr[25], actualArr[25];
int res[25], resSize;
int bestAproach=1e9;

void bestMix(int actualN, int pos, int used){
    if(actualN>n || pos>t){
        return;
    }
    if(n-actualN<bestAproach){
        bestAproach=n-actualN;
        memcpy(res, actualArr, sizeof(actualArr));
        resSize=used;
    }
    actualArr[used]=arr[pos];
    bestMix(actualN+arr[pos], pos+1, used+1);
    bestMix(actualN, pos+1, used);

}

int main(){
    int i;
    while(scanf("%d", &n)!=EOF){
        scanf("%d", &t);
        for(int i=0; i<t; i++){
            scanf("%d", &arr[i]);
        }
        bestAproach=1e9;
        memset(actualArr, 0, sizeof(actualArr));
        bestMix(0, 0, 0);
        int sum=0;
        for(i=0; i<resSize; i++){
            sum+=res[i];
            printf("%d ", res[i]);
        }
        printf("sum:%d\n", sum);
    }
    return 0;
}
