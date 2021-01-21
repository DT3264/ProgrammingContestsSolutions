
// Problem : 11686 - Pick up sticks
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2733
// Memory Limit : 32 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
using namespace std;
template<class T>
using v=vector<T>;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int n, m;
    while(cin >> n >> m){
    	if(n+m==0) break;
    	vi inDegree(n+1);
    	v<vi> adjList(n+1);
    	v<set<int>> fastFind(n+1);
    	for(int i=1; i<=n; i++){
    		inDegree[i]=0;
    		fastFind[0].insert(i);
    	}
    	for(int i=0; i<m; i++){
    		int u, v;
    		cin >> u >> v;
    		adjList[u].push_back(v);
    		int actDegree=++inDegree[v];
    		fastFind[actDegree-1].erase(v);
    		fastFind[actDegree].insert(v);
    	}
    	vi ans;
    	while(fastFind[0].size()>0){
    		auto inWith0=fastFind[0];
    		fastFind[0].clear();
    		for(auto u : inWith0){
    			ans.push_back(u);
    			for(auto &v : adjList[u]){
    				int actDegree=--inDegree[v];
    				fastFind[actDegree+1].erase(v);
    				fastFind[actDegree].insert(v);
    			}
    		}
    	}
    	if(ans.size()==0) cout << "IMPOSSIBLE\n";
    	else for(auto &x : ans) cout << x << "\n";
    }
    return 0;
}
