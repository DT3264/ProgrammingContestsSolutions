    #include<bits/stdc++.h>
    using namespace std;
    int arr[200001];
    int lastOcurr[200001];
    int main(){
        int t, i;
        scanf("%d", &t);
        while(t--){
            memset(lastOcurr, -1, sizeof(lastOcurr));
            int n, z;
            int ans=1e9;
            scanf("%d", &n);
            for(i=0; i<n; i++){
                scanf("%d", &arr[i]);
                if(lastOcurr[arr[i]]!=-1){
                    //printf("%d last: %d\n", arr[i], lastOcurr[arr[i]]);
                    ans=min(ans, i-lastOcurr[arr[i]]+1);
                }
                lastOcurr[arr[i]]=i;
            }
            if(n==1){
                printf("-1\n");
                continue;
            }
            if(ans==1e9){
                ans=-1;
            }
            printf("%d\n", ans);
        }
        return 0;
    }