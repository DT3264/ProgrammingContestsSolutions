#include<bits/stdc++.h>
#define f first
#define s second
#define vi vector<ll>
#define pii pair<ll, ll>
#define ll long long
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll cases;
    cin >> cases;
    while(cases--){
        ll n, m;
        cin >> n >> m;
        if(n==1) cout << 0;
        if(n==2) cout << m;
        if(n>2) cout << m*2;
        cout << "\n";
    }
    return 0;
}
