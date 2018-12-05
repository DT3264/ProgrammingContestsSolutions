#include<stdio.h>
int arr[110];
int main (){
    int n, i, maxN=0, totalElo=0, totalAwruk=0;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        if(arr[i]>maxN) maxN=arr[i];
        totalElo+=arr[i];
    }
    for(i=0; i<n; i++){
        totalAwruk+=maxN-arr[i];
    }
    while(totalAwruk<=totalElo){
        totalAwruk=0;
        maxN++;
        for(i=0; i<n; i++){
            totalAwruk+=maxN-arr[i];
        }
    }
    printf("%d", maxN);
    return 0;
}
