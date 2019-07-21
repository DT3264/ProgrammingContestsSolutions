    #include "bits/stdc++.h"
    #define ll long long
    using namespace std;
    ll sum(ll n){
        return (n*(n+1))/2;
    }
    int main(){
        ll n, k;
        scanf("%lld%lld", &n, &k);
        ll left=1, right=n;
        ll mid, ans=-1;
        while(left<=right && ans==-1){
            mid=left+(right-left)/2;
            ll remainSteps=n-mid;
            ll test=sum(mid);
            //printf("%lld has %lld and remaind %lld\n", mid, test, test-remainSteps);
            if(test-remainSteps>k){
                right=mid-1;
            }
            else if(test-remainSteps<k){
                left=mid+1;
            }
            else if(test-remainSteps==k){
                ans=remainSteps;
            }
        }
        printf("%lld\n", ans);
        return 0;
    }