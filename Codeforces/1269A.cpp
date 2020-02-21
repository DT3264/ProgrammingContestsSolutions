#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool crib[10000001];
void primos(){
    for(ll i=2; i<10000000; i+=i==2 ? 1 : 2){
        if(!crib[i]){
            for(ll j = i*i; j<10000001; j+=i){
                crib[j]=true;
            }
        }
    }
}
int main(){
    primos();
    int n, l, r;
    cin >> n;
    l=1, r=n+1;
    while(!crib[l] || !crib[r]){
        l++;
        r++;
    }
    printf("%d %d\n", r, l);
    return 0;
}
