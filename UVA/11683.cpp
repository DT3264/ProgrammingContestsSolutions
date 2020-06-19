#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<ll>
#define pii pair<ll, ll>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    string str;
    int n, m;
    while(cin >> n && n!=0){
        cin >> m;
        vector<int> vec(m);
        for(int &x : vec){
            cin >> x;
            x=n-x;
        }
        int ans=vec[0];
        for(int i=1; i<m; i++){
            if(vec[i]>vec[i-1]){
                ans+=vec[i]-vec[i-1];
            }
        }
        cout << ans << "\n";
    }
    return 0;

}
