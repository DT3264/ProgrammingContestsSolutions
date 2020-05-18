#include<bits/stdc++.h>
#define f first
#define s second
#define vi vector<ll>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sortVec sort(vec.begin(), vec.end());
#define debug if(printDebug)
bool printDebug=false;
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    while(cin >> n && n!=0){
        vector<int> vec(5);
        map<string, int> popMap;
        map<int, int> countMap;
        for(int i=0; i<n; i++){
            for(int &x : vec){
                cin >> x;
            }
            sortVec;
            string str="";
            for(int &x : vec){
                str+=to_string(x);
            }
            popMap[str]++;
        }
        for(auto &p : popMap){
            countMap[p.s]++;
        }
        int ans=0, timesAns=0;
        for(auto &x : countMap){
            ans=x.f*x.s;
        }
        cout << ans << "\n";
    }
    return 0;
}
