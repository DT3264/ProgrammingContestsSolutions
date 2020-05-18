#include<bits/stdc++.h>
#define f first
#define s second
#define vi vector<ll>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define debug if(printDebug)
bool printDebug=false;
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ll cases;
    cin >> cases;
    string str;
    cin.ignore();
    getline(cin, str);
    while(cases--){
        double trees=0;
        map<string, double> mapa;
        while(getline(cin, str) && str!=""){
            mapa[str]++;
            trees++;
        }
        //sort(mapa.begin(), mapa.end());
        double divisor=100/trees;
        for(auto &p : mapa){
            cout << p.f << " " << fixed << setprecision(4) << divisor*p.s << "\n";
        }
        if(cases>0){
            cout << "\n";
        }
    }
    return 0;
}
