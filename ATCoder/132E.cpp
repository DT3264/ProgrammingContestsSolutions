#include<bits/stdc++.h>
using namespace std;
struct pos{
    int pos;
    int step;
    int round;
};
bool mark[100001][3];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i;
    int n, m;
    int u, v;
    int s, t;
    cin >> n >> m;
    vector<vector<int>> vec(100001);
    for(i=0; i<m; i++){
        cin >> u >> v;
        vec[u].push_back(v);
    }
    cin >> s >> t;
    queue<pos> positions;
    for(i=0; i<vec[s].size(); i++){
        positions.push({vec[s][i], 0, 1});
        //
    }
    int ans=-1;
    while(!positions.empty() && ans==-1){
        pos aPos=positions.front();
        positions.pop();
        if(aPos.pos==t && aPos.step==2){
            ans=aPos.round;
        }
        if(!mark[aPos.pos][aPos.step]){
            mark[aPos.pos][aPos.step]=true;
        }
        else{
            continue;
        }
        for(i=0; i<vec[aPos.pos].size(); i++){
            int newVert=vec[aPos.pos][i];
            int newStep=aPos.step+1;
            int newRound=aPos.round;
            if(newStep>2){
                newStep=0;
                newRound++;
            }
            positions.push({newVert, newStep, newRound});
        }
    }
    cout << ans << "\n";
    return 0;
}
