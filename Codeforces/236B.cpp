#include<stdio.h>
#include<math.h>
#define ll long long
ll a, b, c;
ll total;
ll arr[3];
int upTo[3];
int divsOfEach[10000000];


ll divsOfN(ll n){
    if(divsOfEach[n]!=0) return divsOfEach[n];
    ll divs=0;
    for(ll i=1; i<=sqrt(n); i++){
        if(n%i==0){
            divs++;
            if(n/i!=i){
                divs++;
            }
        }
    }
    divsOfEach[n]=divs;
    return divs;
}

void permu(int pos){
    if(pos==3){
        ll tempMul=1;
        for(int i=0; i<3; i++){
            tempMul*=arr[i];
        }
        ll divsInN=divsOfN(tempMul);
        total+=divsInN;
        return;
    }
    for(int i=1; i<=upTo[pos]; i++){
        arr[pos]=i;
        permu(pos+1);
    }
}

int main(){
    scanf("%lld%lld%lld", &a, &b, &c);
    upTo[0]=a;
    upTo[1]=b;
    upTo[2]=c;
    arr[0]=arr[1]=arr[2]=1;
    permu(0);
    printf("%lld", total);
    return 0;
}
