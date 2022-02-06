#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
bool printDebug=false;
using namespace std;
template<class T>
using v=vector<T>;
int main(){
    // printDebug=true;
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int  n;
    int actCase = 1;
    while((cin >> n) && n > 0){
	    map<int, v<int>> vec;
	    set<int> ids;
	    int u, v;
	    for(int i=0; i<n; i++){
	    	cin >> u >> v;
	    	vec[u].push_back(v);
	    	vec[v].push_back(u);
	    	ids.insert(u);
	    	ids.insert(v);
	    }
	    int nodes=ids.size();
	    int f, t;
	    // cout << "Nodes: " << nodes << endl;
	    while((cin >> f >> t) && f+t > 0){
	    	// cout << "Con "<< t << endl;
	    	int count = 1;
	    	queue<int> aQ, nQ;
	    	aQ.push(f);
	    	map<int, int> vis;
	    	vis[f] = 1;
	    	for(int i=0; i<t; i++){
	    		// cout << "Vuuelta:  " << i  << endl;
	    		while(!aQ.empty()){
		    		int a = aQ.front();
		    		aQ.pop();
		    		for(auto &adj : vec[a]){
		    			if(vis[adj]) continue;
		    			else{
		    				// cout << "Llegando  a " << adj << endl; 
	    					count++;
	    					vis[adj] = 1;
	    					nQ.push(adj);
		    			}
		    		}
		    	}
		    	aQ = nQ;
	    	}
	    	int ans = nodes-count;
	    	printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", actCase++, ans, f, t);
	    }
    }
    return 0;
}
