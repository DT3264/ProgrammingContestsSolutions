#include<stdio.h>
#include<algorithm>
long long arr[100001];
int n;
long long totalSoda;
int main (){
    int i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        totalSoda+=arr[i];
    }
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    std::sort(arr, arr+n);
    if(totalSoda<=arr[n-1]+arr[n-2]){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}
