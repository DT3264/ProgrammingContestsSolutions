#include<bits/stdc++.h>
using namespace std;
struct P{
    int x;
    int id;
};
map<int, int> idToTotal;///saves ID of search; returns total elements in that ID
vector<int> adj[500001];
int memo[500001];
int globalID=1;
int total=0;
void dfs(P act){
    if(memo[act.x]!=0){
        return;
    }
    memo[act.x]=act.id;
    for(int x : adj[act.x]){
        dfs({x, act.id});
    }
    total++;
}
int main(){
    int n, m, p, fP, sP;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> p;
        //cout << "Leyendo: " << p << endl;
        if(p>0){
            cin >> fP;//THe main person of the group
            //cout << fP << " es el principal" << endl;
            for(int j=1; j<p; j++){
                cin >> sP;//Each other pesron in the group
                //cout << fP << "  conoce a " << sP << endl;
                adj[fP].push_back(sP);
                adj[sP].push_back(fP);
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(memo[i]==0){
            total=0;
            dfs({i, globalID});
            idToTotal[globalID]=total;
            globalID++;
        }
        cout << idToTotal[memo[i]] << " ";
    }
    return 0;
}