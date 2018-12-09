#include<stdio.h>
#include<algorithm>
int main(){
    int n, i, arr[100000];
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    std::sort(arr, arr+n);
    int m, q;
    scanf("%d", &m);
    for(i=0; i<m; i++){
        scanf("%d", &q);
        int res=n;
        int left=0, right = n-1, mid;
        while(left<=right){
            mid = left+(right-left+1)/2;
            if(arr[mid]<q) left = mid+1;
            else if(arr[mid]>q){
                right=mid-1;
                res=mid;
            }
            else if(arr[mid]==q) left=mid+1;
        }
        printf("%d\n", res);
    }
    return 0;
}
