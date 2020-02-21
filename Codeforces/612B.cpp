#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, i, sum=0, t;
ll arr[200001];
int main(){
    scanf("%lld", &n);
    for(i=0; i<n; i++){
        scanf("%lld", &t);
        arr[t]=i+1;
    }
    for(i=1; i<n; i++){
        //cout << arr[i] << " ";
        sum+=abs(arr[i]-arr[i+1]);
    }
    cout << sum << endl;
return 0;
}
