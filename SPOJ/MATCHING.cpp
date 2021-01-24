#include<bits/stdc++.h>
using namespace std;
struct BipartiteMatcher {
  vector<vector<int>> G;
  vector<int> L, R, Viz;
  
  //n+1, m+1 on 1-index
  BipartiteMatcher(int n, int m) :
  G(n), L(n, -1), R(m, -1), Viz(n) {}
  
  void AddEdge(int a, int b) {
    G[a].push_back(b);
  }
  
  bool Match(int node) {
    if (Viz[node])
      return false;
    Viz[node] = true;
    
    for (auto vec : G[node]) {
      if (R[vec] == -1) {
        L[node] = vec;
        R[vec] = node;
        return true;
      }
    }
    
    for (auto vec : G[node]) {
      if (Match(R[vec])) {
        L[node] = vec;
        R[vec] = node;
        return true;
      }
    }
    
    return false;
  }
  
  int Solve() {
    int ok = 1;
    while (ok--) {
      fill(Viz.begin(), Viz.end(), 0);
      for (int i = 0; i < (int)L.size(); ++i)
        if (L[i] == -1)
          ok |= Match(i);
    }
    
    int ret = 0;
    for (int i = 0; i < L.size(); ++i)
      ret += (L[i] != -1);
    return ret;
  }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int n, m, k;
    int u, v;
    cin >> n >> m >> k;
    BipartiteMatcher bpm(n+1, m+1);
    for(int i=0; i<k; i++){
    	cin >> u >> v;
    	bpm.AddEdge(u, v);
    }
    cout << bpm.Solve() << "\n";
    return 0;
}
