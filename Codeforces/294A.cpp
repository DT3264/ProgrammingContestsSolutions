#include<bits/stdc++.h>
using namespace std;
int arr[102];
int main(){
    int i;
    int n, k;
    int x, y;
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    for(i=0; i<k; i++){
        scanf("%d%d", &x, &y);
        arr[x-1]+=y-1;
        arr[x+1]+=arr[x]-y;
        arr[x]=0;
    }
    for(i=1; i<=n; i++){
        printf("%d\n", arr[i]);
    }
}