#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;
ll n, k;
ll tempN;
vector<ll> pow2, arr;

void loadPowers(){
    for(ll i=0; pow(2, i)<=n; i++){
        pow2.push_back(pow(2, i));
    }
}

void reachN(){
    for(ll i=pow2.size()-1; i>=0; i--){
        if(pow2[i]<=tempN){
            arr.push_back(pow2[i]);
            tempN-=pow2[i];
        }
    }
}

int main(){
    ll i;
    scanf("%lld%lld", &n, &k);
    loadPowers();
    tempN=n;
    reachN();
    sort(arr.begin(), arr.end());
    int actualPos = 0;
    while(arr.size()<k){
        if(arr[actualPos]>1){
            arr.push_back(arr[actualPos]/2);
            arr[actualPos]/=2;
        }
        else{
            actualPos++;
            if(actualPos==arr.size()){
                break;
            }
        }
    }
    if(arr.size()==k){
        sort(arr.begin(), arr.end());
        printf("YES\n");
        for(i=0; i<arr.size(); i++){
            printf("%lld ", arr[i]);
        }
    }
    else{
        printf("NO");
    }
    return 0;
}
