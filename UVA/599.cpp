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
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases;
    cin >> cases;
    cin.ignore();
    string str;
    while(cases--){
        vector<vi> vec(26);
        while(cin >> str && str[0]!='*'){
            int u=str[1]-'A';
            int v=str[3]-'A';
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        cin >> str;
        vector<bool> visited(27, false);
        int trees=0;
        int acorns=0;
        for(int i=0; i<str.size(); i+=2){
            int u=str[i]-'A';
            if(!visited[u]){
                int cant=0;
                visited[u]=true;
                cant++;
                queue<int> q;
                for(int x : vec[u]){
                    q.push(x);
                }
                while(!q.empty()){
                    int v=q.front();
                    q.pop();
                    visited[v]=true;
                    cant++;
                    for(int x : vec[v]){
                        if(!visited[x]) q.push(x);
                    }
                }
                if(cant==1) acorns++;
                else trees++;
            }
        }
        cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s).\n";
    }
    return 0;
}
