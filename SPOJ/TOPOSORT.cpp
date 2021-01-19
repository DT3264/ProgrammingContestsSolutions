#include<bits/stdc++.h>
#define y1 yy
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
#define noDebug if(!printDebug)
using namespace std;
template<class T>
using v=vector<T>;   
bool printDebug=false;
v<vi> adjList;
vi inDegree;
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    priority_queue<int, vi, greater<int>> pq;
    int n, m;
    cin >> n >> m;
    adjList.assign(n+1, {});
    inDegree.assign(n+1, 0);
    int u, v;
    for(int i=0; i<m; i++){
    	cin >> u >> v;
    	adjList[u].push_back(v);
    	inDegree[v]++;
    }
    vi ans;
    for(int i=1; i<=n; i++) if(inDegree[i]==0) pq.push(i);
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
    if(ans.size()==n){
    	for(int &u : ans) cout << u << " ";
    }
    else cout << "Sandro fails.";
    return 0;
}
