
// Problem : 11749 - Poor Trade Advisor
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2849
// Memory Limit : 32 MB
// Time Limit : 3000 ms
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
struct Node{
	int to;
	int cost;
};
v<v<Node>> vec;
v<bool> visited;
int maxPlaces;
double maxAvg;
int maxPPA;
int actAns;
void visit(int pos){
	actAns++;
	for(auto &n : vec[pos]){
		if(!visited[n.to] && n.cost==maxPPA){
			visited[n.to]=1;
			visit(n.to);
		}
	}
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    int n, m;
    while(cin >> n >> m){
    	maxPlaces=0;
    	maxAvg=0;
    	if(n==0 && m==0) break;
    	vec=v<v<Node>>(n+1);
    	visited=v<bool>(n+1, 0);
    	maxPPA=INT_MIN;
    	maxPlaces=0;
    	int u, v, c;
    	for(int i=0; i<m; i++){
    		cin >> u >> v >> c;
    		vec[u].push_back({v, c});
    		vec[v].push_back({u, c});
    		maxPPA=max(maxPPA, c);	
    	}
    	for(int i=1; i<=n; i++){
    		if(vec[i].size()>0){
    			visited[i]=1;
    			actAns=0;
    			visit(i);
    			maxPlaces=max(maxPlaces, actAns);
    			visited[i]=0;
    		}
    	}
    	cout << maxPlaces << "\n";
    }
    return 0;
}
