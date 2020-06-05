#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define sortVec sort(vec.begin(), vec.end());
#define debug if(printDebug)
bool printDebug=false;
using namespace std;
int main(){
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int n, m;
    int k, t, val;
    while(cin >> n >> m){
        map<int, vector<int>> mapa;
        for(int i=0; i<n; i++){
            cin >> t;
            mapa[t].push_back(i+1);
        }
        for(int i=0; i<m; i++){
            cin >> k >> val;
            if(mapa[val].size()>0){
                if(mapa[val].size()>k-1){
                    cout << mapa[val][k-1] << "\n";
                }
                else{
                    cout << "0\n";
                }
            }
            else{
                cout << "0\n";
            }
        }
    }
    return 0;
}
