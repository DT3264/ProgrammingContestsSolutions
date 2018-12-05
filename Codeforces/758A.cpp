#include<stdio.h>
int n, i, arr[1000], maxN, need;
int main(){
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        if(arr[i]>maxN) maxN=arr[i];
    }
    for(i=0; i<n; i++){
        need+=maxN-arr[i];
    }
    printf("%d", need);
    return 0;
}

