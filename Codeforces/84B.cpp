#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, i;
    long long arr[100001];
    cin >> n;
    for(i=0; i<n; i++){
        cin >> arr[i];
    }
    long long ans=0;
    long long consec=0;
    int nIndex;
    for(i=0; i<n; i++){
        nIndex=i+1;
        consec=0;
        if(arr[nIndex]==arr[i]){
            while(nIndex<n && arr[nIndex]==arr[i]){
                consec++;
                ans+=consec;
                nIndex++;
            }
            i=nIndex-1;
        }
    }
    ans+=n;
    cout << ans << "\n";
}
