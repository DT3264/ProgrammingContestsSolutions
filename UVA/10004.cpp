
// Problem : 10004 - Bicoloring
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=945
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
const int INF=-1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int n, m;
    while(cin >> n){
    	if(n==0) break;
    	cin >> m;
    	v<vi> adjList(n);
    	vi colors(n, -1);
    	int u, v;
    	for(int i=0; i<m; i++){
    		cin >> u >> v;
    		adjList[u].push_back(v);
    		adjList[v].push_back(u);
    	}
    	queue<int> q;
    	q.push(0);
    	colors[0]=0;
    	bool isBicolor=true;
    	while(!q.empty() && isBicolor){
    		int u=q.front();
    		q.pop();
    		for(auto &v : adjList[u]){
    			if(colors[v]==INF){
    				colors[v]=!colors[u];
    				q.push(v);
    			}
    			else if(colors[v]==colors[u]){
    				isBicolor=false;
    			}
    		}
    	}
    	cout << (isBicolor ? "" : "NOT ") << "BICOLORABLE.\n";
    }
    return 0;
}
