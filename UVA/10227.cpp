#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define si set<int>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
bool areEqual(si &v1, si &v2){
    int pos=0;
    if(v1.size()!=v2.size()) return false;
    auto i1=v1.begin();
    auto i2=v2.begin();
    while(pos!=v1.size()){
        if(*i1==*i2){
            pos++;
            i1++;
            i2++;
        }
        else return false;
    }
    return true;
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases;
    cin >> cases;
    while(cases--){
        int p, t;
        cin >> p >> t;
        cin.ignore();
        string str;
        vector<bool> searched(p, false);
        vector<set<int>> vec(p, set<int>());
        int u, v;
        while(getline(cin, str) && str!=""){
            stringstream ss(str);
            ss >> u >> v;
            u--;
            vec[u].insert(v);
        }
        int ans=0;
        for(int i=0; i<vec.size(); i++){
            if(searched[i]) continue;
            for(int j=i+1; j<vec.size(); j++){
                if(!searched[j] && areEqual(vec[i], vec[j])) searched[j]=true;
            }
            ans++;
        }
        cout << ans << "\n";
        if(cases>0) cout << "\n";
    }
    return 0;

}
