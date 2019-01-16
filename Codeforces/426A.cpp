#include<stdio.h>
#include<algorithm>
int arr[101];
int main (){
    int n, m, i, t=0;
    bool canPlay=false;
    scanf("%d%d", &n, &m);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        t+=arr[i];
    }
    std::sort(arr, arr+n);
    if(t-arr[n-1]<=m){
        canPlay=true;
    }
    printf("%s\n", (canPlay ? "YES" : "NO"));
    return 0;
}