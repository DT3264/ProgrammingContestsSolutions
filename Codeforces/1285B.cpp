#include<bits/stdc++.h>
using namespace std;
int main(){
    long long c, n, i, j;
    long long arr[100000];
    long long sum;
    cin >> c;
    while(c--){
        cin >> n;
        sum=0;
        bool toZero = false;
        for(i=0; i<n; i++){
            cin >> arr[i];
            sum+=arr[i];
            if(sum <= 0){
                toZero=true;
            }
        }
        sum=0;
        for(i=n-1; i>=0; i--){
            sum+=arr[i];
            if(sum <= 0){
                toZero=true;
            }
        }
        cout << (toZero ? "NO" : "YES") << "\n";
    }
return 0;
}
