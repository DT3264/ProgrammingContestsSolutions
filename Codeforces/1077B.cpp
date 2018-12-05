#include<stdio.h>
int n, i, arr[1000], dist;
int main(){
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(i=1; i<n-1; i++){
        if(arr[i]==0 && arr[i-1]==1 && arr[i+1]==1){
            dist++;
            arr[i+1]=0;///turn off the light
            ///so the next neighbour could sleep in case he doens't
        }
    }
    printf("%d", dist);
    return 0;
}
