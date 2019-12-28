#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        long long k;
        cin >> k;
        if(k<=14){
            cout << "NO\n";
            continue;
        }
        long long aprox = k/14;
        k-=aprox*14;
        cout << (k >= 1 && k<=6 ? "YES" : "NO") << "\n";
    }
}
