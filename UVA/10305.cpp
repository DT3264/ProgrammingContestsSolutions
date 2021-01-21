
// Problem : 10305 - Ordering Tasks
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1246
// Memory Limit : 32 MB
// Time Limit : 3000 ms
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
    	v<vi> adjList(n+1);
    	vi inDegree(n+1, 0);
    	priority_queue<int, vi, greater<int>> pq;
    	for(int i=0; i<m; i++){
    		int u, v;
    		cin >> u >> v;
    		adjList[u].push_back(v);
    		inDegree[v]++;
    	}
    	for(int i=1; i<=n; i++){
    		if(inDegree[i]==0) pq.push(i);
    	}
    	vi ans;
    	while(!pq.empty()){
    		int u=pq.top();
    		pq.pop();
    		ans.push_back(u);
    		for(auto &v : adjList[u]){
    			inDegree[v]--;
    			if(inDegree[v]==0) pq.push(v);
    		}
    	}
    	for(int i=0; i<ans.size(); i++){
    		cout << ans[i] <<" \n"[i==ans.size()-1];
    	}
    }
    return 0;
}
