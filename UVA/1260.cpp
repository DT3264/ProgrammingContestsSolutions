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
        int n;
        cin >> n;
        vector<int> vec(n);
        int ans=0;
        for(int &x : vec) cin >> x;
        for(int i=1; i<vec.size(); i++){
            for(int j=0; j<i; j++){
                ans+=vec[j]<=vec[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;

}
