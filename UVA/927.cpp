#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define si set<int>
#define y1 yy
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases;
    cin >> cases;
    while(cases--){
        int n, d, k;
        cin >> n;
        vector<ll> vec(n+1);
        for(ll &x : vec){
            cin >> x;
        }
        cin >> d >> k;
        int actPos=0, actN=1;
        while(actPos<k){
            actPos+=actN*d;
            actN++;
        }
        actN--;
        ll ans=0;
        for(int i=0; i<vec.size(); i++){
            ans+=vec[i]*pow(actN, i);
        }
        cout << ans << "\n";
    }
    return 0;

}
