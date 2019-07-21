    #include "bits/stdc++.h"
    #define ll long long
    using namespace std;
    int buk[100000];
    int main(){
        int n, k, i, t;
        scanf("%d%d", &n, &k);
        for(i=0; i<n; i++){
            scanf("%d", &t);
            buk[t]++;
        }
        int ans=n;
        bool alternate=true;
        for(i=0; i<k+1; i++){
            if(buk[i]%2!=0){
                if(!alternate){
                    ans--;
                }
                alternate=!alternate;
            }
        }
        printf("%d\n", ans);
        return 0;
    }