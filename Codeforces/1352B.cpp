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
    int cases;
    cin >> cases;
    while(cases--){
        int n, m;
        cin >> n >> m;
        bool can=true, withOne=false;
        int v1=n-(m-1);
        int v2=n-((m-1)*2);
        if(v1%2!=0 && v1>0){
            withOne=true;
            can=true;
        }
        else if(v2%2==0 && v2>0){
            withOne=false;
            can=true;
        }
        else{
            can=false;
        }
        if(can){
            cout << "YES\n";
            cout << (withOne ? v1 : v2) << " ";
            for(int i=1; i<m; i++){
                cout << (withOne ? 1 : 2) << " ";
            }
            cout << "\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
