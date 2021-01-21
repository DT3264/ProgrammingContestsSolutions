
// Problem : Answer the boss!
// Contest : SPOJ - Classical
// URL : https://www.spoj.com/problems/RPLA/
// Memory Limit : 1536 MB
// Time Limit : 1000 ms
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
    int cases;
    cin >> cases;
    for(int actCase=1; actCase<=cases; actCase++){
    	if(actCase>1) cout << "\n";
    	cout << "Scenario #" << actCase << ":\n";
    	int n, m;
    	cin >> n >> m;
    	v<vi> adjList(n);
    	vi inDegree(n, 0);
    	for(int i=0; i<m; i++){
    		int u, v;
    		cin >> v >> u;
    		adjList[u].push_back(v);
    		inDegree[v]++;
    	}
    	priority_queue<int, vi, greater<int>> pq, tempPq;
    	for(int i=0; i<n; i++){
    		if(inDegree[i]==0) pq.push(i);
    	}
    	int rank=1;
    	while(!pq.empty()){
    		int u=pq.top();
    		pq.pop();
    		cout << rank << " " << u << "\n";
    		for(int &v : adjList[u]){
    			inDegree[v]--;
    			if(inDegree[v]==0){
    				tempPq.push(v);
    			}
    		}
    		if(pq.empty()){
    			pq=tempPq;
    			while(tempPq.size()>0) tempPq.pop();
    			rank++;
    		}
    	}
    }
    return 0;
}
