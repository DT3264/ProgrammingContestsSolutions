#include <bits/stdc++.h>
using namespace std;
int main(){
    int ans=0, cont=0;
    int n, i;
    cin >> n;
    int lastT=-1, t;
    for(i=0; i<n; i++){
        cin >> t;
        if(t>lastT){
            cont=0;
        }
        else{
            cont++;
        }
        ans=max(ans, cont);
        lastT=t;
    }
    cout << ans << "\n";
}
