#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    int i, j, n;
    int arr[10000];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0; i<n; i++){
            scanf("%d", &arr[i]);
        }
        sort(arr, arr+n);
        bool can=true;
        int ans=1;
        for(i=2; i<=1000; i++){
            int cont=0;
            for(j=0; j<n; j++){
                if(arr[j]>=i){
                    cont++;
                }
            }
            if(cont>=i){
                ans=i;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}