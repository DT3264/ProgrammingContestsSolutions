#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int x=1;
    int ans=1;
    while(x<n){
        x++;
        ans+=(x-1)*4;
    }
    cout << ans << "\n";
    return 0;
}
