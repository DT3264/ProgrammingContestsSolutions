#include<stdio.h>
int n, c, i;
int limS, radS;
int limT, radT;
int arr[2][10000];

int maxN(int a, int b){
    return a>b ? a : b;
}

int main(){
    scanf("%d%d", &n, &c);
    for(i=0; i<n; i++){
        scanf("%d", &arr[0][i]);
    }
    for(i=0; i<n; i++){
        scanf("%d", &arr[1][i]);
    }
    for(i=0; i<n; i++){
        limT+=arr[1][i];
        limS+=maxN(arr[0][i]-(c*limT), 0);
        radT+=arr[1][n-i-1];
        radS+=maxN(arr[0][n-i-1]-(c*radT), 0);
    }
    if(limS>radS){
        printf("Limak");
    }
    else if(radS>limS){
        printf("Radewoosh");
    }
    else{
        printf("Tie");
    }
    return 0;
}
