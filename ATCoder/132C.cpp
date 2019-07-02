#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, i;
    int arr[100001];
    cin >> n;
    for(i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    cout << (arr[n/2]-arr[(n/2)-1]);
    return 0;
}
