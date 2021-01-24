#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
template<class T>
using v=vector<T>;

int id=1;
map<ll, ll> idFromVal, valFromID;

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
  
  v<ll> Solve() {
    int ok = 1;
    while (ok--) {
      fill(Viz.begin(), Viz.end(), 0);
      for (int i = 0; i < (int)L.size(); ++i)
        if (L[i] == -1)
          ok |= Match(i);
    }
    v<ll> ans;
    for (int i = 0; i < L.size(); ++i){
      //cout << valFromID[L[i]] << "\n";
      if(L[i] == -1) return {};
      ans.push_back(valFromID[L[i]]);
    }
    return ans;
  }
};
void agregaID(ll val){
	//cout << "ids[" << val << "]=" << idFromVal[val] << "\n";
	if(idFromVal[val]==0) idFromVal[val]=id++;
	valFromID[idFromVal[val]]=val;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int n;
    cin >> n;
    v<pll> vec(n);
    for(auto &p : vec){
    	cin >> p.f >> p.s;
    	agregaID(p.f+p.s);
    	agregaID(p.f-p.s);
    	agregaID(p.f*p.s);
    }
    BipartiteMatcher bpm(n, id);
    for(int i=0; i<n; i++){
    	auto &p=vec[i];
    	bpm.AddEdge(i, idFromVal[p.f+p.s]);
    	bpm.AddEdge(i, idFromVal[p.f-p.s]);
    	bpm.AddEdge(i, idFromVal[p.f*p.s]);
    }
    auto ans=bpm.Solve();
    if(ans.size()==0) cout << "Impossible\n";
    else{
    	for(int i=0; i<n; i++){
    		ll v1=vec[i].f;
    		ll v2=vec[i].s;
    		ll vA=ans[i];
    		char sign;
    		if(v1+v2==vA){
    			sign='+';
    		}
    		else if(v1-v2==vA){
    			sign='-';
    		}
    		else if(v1*v2==vA){
    			sign='*';
    		}
    		cout << v1 << " " << sign << " " << v2 << " = " << vA << "\n";
    	}
    }
    return 0;
}
