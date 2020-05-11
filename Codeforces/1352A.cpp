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
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        int val;
        vector<int> ans;
        cin >> val;
        string str=to_string(val);
        int pow=1;
        for(int i=str.size()-1; i>=0; i--){
            if(str[i]!='0'){
                ans.push_back((str[i]-'0')*pow);
            }
            pow*=10;
        }
        cout << ans.size() << "\n";
        for(int x : ans){
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
