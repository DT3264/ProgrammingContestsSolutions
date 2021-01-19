
// Problem : 11060 - Beverages
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2001
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
    cin.tie(0);
    int n, m;
    int actCase=1;
    while(cin >> n){
    	v<vi> adjList(n);
    	vi inDegree(n, 0);
    	v<string> drinks(n);
    	map<string, int> ids;
    	string sU, sV;
    	priority_queue<int, vi, greater<int>> pq;
    	vi ans;
    	for(int i=0; i<n; i++){
    		cin >> drinks[i];
    		ids[drinks[i]]=i;
    	}
    	cin >> m;
    	for(int i=0; i<m; i++){
    		cin >> sU >> sV;
    		int u=ids[sU];
    		int v=ids[sV];
    		adjList[u].push_back(v);
    		inDegree[v]++;
    	}
    	for(int i=0; i<n; i++){
    		int u=ids[drinks[i]];
    		if(inDegree[u]==0) pq.push(u);
    	}
    	while(!pq.empty()){
    		int u=pq.top();
    		pq.pop();
    		ans.push_back(u);
    		for(auto &v : adjList[u]){
    			inDegree[v]--;
    			if(inDegree[v]>0) continue;
    			pq.push(v);
    		}
    	}
    	cout << "Case #" << actCase << ": Dilbert should drink beverages in this order: ";
    	for(int i=0; i<ans.size(); i++){
    		cout << drinks[ans[i]] << " ."[i==ans.size()-1];
    	}
    	actCase++;
    	cout << "\n\n";
    }
    return 0;
}
