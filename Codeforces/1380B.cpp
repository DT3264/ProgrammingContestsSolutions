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
    int cases, n;
    cin >> cases;
    while(cases--){
        int r=0, p=0, s=0;
        string str;
        cin >> str;
        for(char &c : str){
            if(c=='R') r++;
            else if(c=='P') p++;
            else if(c=='S') s++;
        }
        char maxN;
        if(r>=p && r>=s) maxN='P';
        if(p>=r && p>=s) maxN='S';
        if(s>=r && s>=p) maxN='R';
        for(char &c : str) cout << maxN;
        cout << "\n";
    }
    return 0;
}
