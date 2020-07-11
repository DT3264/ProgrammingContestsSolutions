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
    int n;
    int actCase=1;
    while(cin >> n){
        if(n==0) break;
        cout << "Case " << actCase++ << ":\n";
        vector<int> vec(n);
        for(auto &x : vec) cin >> x;
        int q;
        cin >> q;
        sort(vec.begin(), vec.end());
        int val;
        while(q--){
            cin >> val;
            int closest=1e9;
            for(int i=0; i<n; i++){
                for(int j=i+1; j<n; j++){
                    if(i==j) continue;
                    int sum=vec[i]+vec[j];
                    if(abs(sum-val)<abs(closest-val)){
                        closest=sum;
                    }
                }
            }
            cout << "Closest sum to " << val << " is " << closest << ".\n";
        }
    }
    return 0;

}
