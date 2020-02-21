#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, i, t, total=0, ans=0;
    cin >> n;
    for(i=0; i<n; i++){
        cin >> t;
        total += t;
    }
    total--;
    total = total%(n+1);
    for(i=0; i<5; i++){
        total++;
        total%=(n+1);
        if(total!=0){
            ans++;
        }
    }
    cout << ans << endl;
return 0;
}
