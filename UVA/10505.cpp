
// Problem : 10505 - Montesco vs Capuleto
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1446
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
v<vi> adjList;
vi colors;
int getMaxFrom(int x){
	int colorCount[2]={0, 0};
	bool isValid=true;
	queue<int> q;
	q.push(x);
	colors[x]=0;
	colorCount[0]++;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto &v : adjList[u]){
			if(colors[v]==INF){
				q.push(v);
				colors[v]=!colors[u];
				colorCount[colors[v]]++;
			}
			else if(colors[v]==colors[u]){
				//Invalid state reached
				isValid=0;
			}
		}
	}
	//If cannot be colored, max is 0
	if(!isValid) return 0;
	return max(colorCount[0], colorCount[1]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	int n;
    	cin >> n;
    	adjList.assign(n+1, {});
    	colors.assign(n+1, INF);
    	for(int i=1; i<=n; i++){
    		int m, v;
    		cin >> m;
    		for(int j=0; j<m; j++){
    			cin >> v;
    			//Just ignore indexes greater than N
    			if(v>n) continue;
    			adjList[i].push_back(v);
    			adjList[v].push_back(i);
    		}
    	}
    	int ans=0;
    	for(int i=1; i<=n; i++){
    		if(colors[i]==INF){
    			ans+=getMaxFrom(i);
    		}
    	}
    	cout << ans << "\n";
    }	
    return 0;
}
