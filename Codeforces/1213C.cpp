#include <bits/stdc++.h>
using namespace std;
long long unsigned q, n, m, i, lastM, arr[10];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--){
        cin >> n >> m;
        if(m>n){
            cout << "0" << "\n";
            continue;
        }
        arr[0]=m;
        long long ans=0;
        for(i=1; i<10; i++){
            arr[i]=arr[i-1]+m;
        }
        lastM=arr[9];
        long long unsigned iter=n/lastM;
        long long unsigned upTo=lastM*(n/lastM);
        for(i=0; i<10; i++){
            ans+=iter*(arr[i]%10);
        }
        upTo+=m;
        while(upTo<=n){
            ans+=upTo%10;
            upTo+=m;
        }
        cout << ans << "\n";
    }
}
