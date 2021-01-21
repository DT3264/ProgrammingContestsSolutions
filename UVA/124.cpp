
// Problem : 124 - Following Orders
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=60
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
int c2i(char c){
	return c-'a';
}
char i2c(int i){
	return i+'a';
}
vi actTopo;
v<vi> adjList;
vi inDegree;
int n;
void reset(){
	adjList.assign(28, {});
	inDegree.assign(28, -1);
	n=0;
}
void topo(int u, int pos){
	actTopo[pos]=u;
	if(pos==n-1){
		for(auto &x : actTopo) cout << i2c(x);
		cout << "\n";
		return;
	}
	for(auto &v : adjList[u]){
		inDegree[v]--;
	}
	for(int v=0; v<27; v++){
		if(inDegree[v]==0){
			inDegree[v]=-1;
			topo(v, pos+1);
			inDegree[v]=0;
		}
	}
	for(auto &v : adjList[u]){
		inDegree[v]++;
	}
}
int main(){
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    string s1, s2;
    int actCase=1;
    while(getline(cin, s1)){
    	getline(cin, s2);
    	if(actCase++>1) cout << "\n";
    	reset();
    	for(int i=0; i<s1.size(); i+=2){
    		int u=c2i(s1[i]);
    		inDegree[u]=0;
    		n++;
    	}
    	actTopo.resize(n);
    	for(int i=0; i<s2.size(); i+=4){
    		int u=c2i(s2[i]);
    		int v=c2i(s2[i+2]);
    		adjList[u].push_back(v);
    		inDegree[v]++;
    	}
    	for(int i=0; i<27; i++){
    		if(inDegree[i]==0){
    			inDegree[i]=-1;
    			topo(i, 0);
    			inDegree[i]=0;
    		}
    	}
    }
    return 0;
}
