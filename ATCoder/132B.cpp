#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, i;
    int arr[20];
    cin >> n;
    for(i=0; i<n; i++){
        cin >> arr[i];
    }
    int tArr[3];
    int ans=0;
    for(i=1; i<n-1; i++){
        tArr[0]=arr[i-1];
        tArr[1]=arr[i];
        tArr[2]=arr[i+1];
        sort(tArr, tArr+3);
        if(tArr[1]==arr[i]){
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
