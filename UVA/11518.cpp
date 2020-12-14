
// Problem : 11518 - Dominos 2
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2513
// Memory Limit : 32 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
v<vi> vec;
v<bool> visited;
int ans=0;
void dfs(int pos){
	if(visited[pos]) return;
	visited[pos]=true;
	ans++;
	for(int &x : vec[pos]) dfs(x);
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    int cases;
    cin >> cases;
    while(cases--){
    	int n, m, l;
    	cin >> n >> m >> l;
    	ans=0;
    	vec=v<vi>(n+1);
    	visited=v<bool>(n+1, 0);
    	int u, v;
    	for(int i=0; i<m; i++){
    		cin >> u >> v;
    		vec[u].push_back(v);
    	}
    	for(int i=0; i<l; i++){
    		int v;
    		cin >> v;
    		dfs(v);
    	}
    	cout << ans << "\n";
    }
    return 0;
}
