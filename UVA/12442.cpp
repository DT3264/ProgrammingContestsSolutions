
// Problem : 12442 - Forwarding Emails
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3873
// Memory Limit : 32 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define y1 yy
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
struct Cycle{
	int start;
	int size;
};
vi dist, to;
vi visited, recurVisited;
Cycle findCycle(int pos, int step){
	//Visited in prev cycle searches
	if(visited[pos]) return {-1, -1};
	//Not visited in this search
	if(!recurVisited[pos]){
		recurVisited[pos]=true;
		dist[pos]=step;
		auto toReturn=findCycle(to[pos], step+1);
		visited[pos]=true;
		recurVisited[pos]=false;
		dist[pos]=-1;
		return toReturn;
	}
	//Found a cycle
	else return {pos, step-dist[pos]};
}
void setCycle(int &start, int pos, int &size){
	dist[pos]=size;
	if(pos!=start) setCycle(start, to[pos], size);
}
int getDist(int pos){
	if(dist[pos]!=-1) return dist[pos];
	else{
		dist[pos]=getDist(to[pos])+1;
		return dist[pos];
	}
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int cases;
    int actCase=1;
    cin >> cases;
    while(cases--){
    	int n;
    	int u, v;
    	cin >> n;
    	dist=vi(n+1, -1);
    	to=vi(n+1, -1);
    	recurVisited=vi(n+1, 0);
    	visited=vi(n+1, 0);
    	for(int i=0; i<n; i++){
    		cin >> u >> v;
    		to[u]=v;
    	}
    	Cycle actCycle;
    	for(int i=1; i<=n; i++){
    		actCycle={-1, -1};
    		if(!visited[i]) actCycle=findCycle(i, 1);
    		if(actCycle.start!=-1) setCycle(actCycle.start, to[actCycle.start], actCycle.size);
    	}
    	int ans=0;
    	int maxN=0;
    	for(int i=1; i<=n; i++){
    		if(dist[i]==-1) getDist(i);
    		maxN=max(maxN, dist[i]);
    	}
    	for(int i=1; i<=n && ans==0; i++){
    		if(dist[i]==maxN) ans=i;
    	}
    	cout << "Case " << actCase++ << ": " << ans << "\n";
    }
    return 0;
}
