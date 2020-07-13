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
        int n, m;
        cin >> n >> m;
        vector<int> vec(n);
        for(int &x : vec) cin >> x;
        sort(vec.begin(), vec.end());
        int left=n-1, right=n-1;
        int ans=0;
        while(left>=0){
            int val=vec[left]*((right-left)+1);
            //cout << "Left: " << left << "; Right: " << right << "\n";
            //cout << val << " >=" << m << "? " << (val>=m) << " \n";
            if(val<m) left--;
            else if(val>=m){
                ans++;
                left--;
                right=left;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
