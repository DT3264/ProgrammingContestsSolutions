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
        ll steps=ceil((double)m/(double)(n-1));
        ll aproxVal=(steps*n)-1;
        ll val=aproxVal-((steps*(n-1))-m);
        cout << val << "\n";
    }
    return 0;
}
