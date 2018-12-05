#include <stdio.h>
#include <algorithm>
#include <math.h>
long long arr[10000000];
int main(){
    long long i, j, n, s;
    scanf("%lld %lld", &n, &s);
    for(i=0; i<n; i++){
        scanf("%lld", &arr[i]);
    }
    std::sort(arr, arr+n);
    long long total=0, pos = 0;

    pos = n/2;
    if(arr[pos]>s){
        for(i=pos; i>=0 && arr[i]>s; i--){
            total+=abs(s-arr[i]);
            arr[i]=s;
        }
    }
    if(arr[pos]<s){
        for(i=pos; i<n && arr[i]<s; i++){
            total+=abs(s-arr[i]);
            arr[i]=s;
        }
    }
    printf("%lld", total);
    return 0;
}
