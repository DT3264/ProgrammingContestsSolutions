#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define si set<int>
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
    string str;
    cin >> cases;
    while(cases--){
        cin >> str;
        pll parent={1,1}, left={0, 1}, right={1, 0};
        for(char &c : str){
            if(c=='R') left=parent;
            else if(c=='L') right=parent;
            parent={left.f+right.f, left.s+right.s};
        }
        cout << parent.f << "/" << parent.s << "\n";
    }
    return 0;

}
