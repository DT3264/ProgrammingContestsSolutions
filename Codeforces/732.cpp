#include<bits/stdc++.h>
using namespace std;
int arr[501];
int main(){
    int n, k, i;
    scanf("%d%d", &n, &k);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int actualW=arr[0];
    int ans=0;
    for(i=1; i<n; i++){
        if(actualW+arr[i]<k){
            ans+=k-(actualW+arr[i]);
            arr[i]+=k-(actualW+arr[i]);
        }
        actualW-=arr[i-1];
        actualW+=arr[i];
    }
    printf("%d\n", ans);
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
