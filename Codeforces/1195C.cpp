#include "bits/stdc++.h"
#define ll long long
using namespace std;
int main(){
    ll arr1[100003];
    ll arr2[100003];
    arr1[0]=0, arr1[1]=0;
    arr2[0]=0, arr2[1]=0;
    ll n, i;
    scanf("%lld", &n);
    for(i=2; i<n+2; i++){
        scanf("%lld", &arr1[i]);
    }
    for(i=2; i<n+2; i++){
        scanf("%lld", &arr2[i]);
    }
    for(i=2; i<n+2; i++){
        ll actN1=arr1[i];
        ll actN2=arr2[i];
        arr1[i]=max(arr2[i-1], arr2[i-2]) + actN1;
        arr2[i]=max(arr1[i-1], arr1[i-2]) + actN2;
    }
    ll ans=max(arr1[n+1], arr2[n+1]);
    printf("%lld\n", ans);
    return 0;
}
