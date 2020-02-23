#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool can(ll x, ll y){
    return y>x && y<=(x*2);
}
int main(){
    ll n;
    cin >> n;
    vector<ll> vec(n);
    for(ll &x:vec){
        cin >> x;
    }
    int best=1;
    int l=0, r=1;
    int cont=1;
    while(r<n){
        if(can(vec[r-1], vec[r])){
            r++;
            cont++;
        }
        else{
            l=r;
            r++;
            cont=1;
        }
        //cout << cont << " vs " << best << "**\n";
        best=max(best, cont);
    }
    cout << best << endl;
}