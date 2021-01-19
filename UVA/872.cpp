
// Problem : 872 - Ordering
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=813
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
int n;
set<string> strings;
vi visited(28, 0);
vi inDegree(28);
v<vi> adjList(28);
vi actualTopo;
void reset(){
    strings.clear();
	visited.assign(28, 0);
	//Initially every node is unreachable (-1)
	inDegree.assign(28, -1);
	adjList.assign(28, {});
}
void topoSort(int u, int pos){
	if(visited[u]) return;
	actualTopo[pos]=u;
	if(pos==n-1){
		string str="";
		for(auto &x : actualTopo){
			str+=x+'A';
		}
		strings.insert(str);
		return;
	}
	visited[u]=1;
	for(auto &v : adjList[u]){
		inDegree[v]--;
	}
	for(int i=0; i<=27; i++){
		if(inDegree[i]==0){//Is reachable
			topoSort(i, pos+1);
		}
	}
	for(auto &v : adjList[u]){
		inDegree[v]++;
	}
	visited[u]=0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int cases;
    cin >> cases;
    cin.ignore();
    string s1, s2;
    for(int actCase=1; actCase<=cases; actCase++){
    	if(actCase>1) cout << "\n";
		reset();
    	
    	//1.Read
    	getline(cin, s1);
    	getline(cin, s1);
    	getline(cin, s2);
		set<int> letters;
    	int u, v;
    	for(int i=0; i<s1.size(); i+=2){
    		u=s1[i]-'A';
    		letters.insert(u);
    		inDegree[u]=0;//This node is reachable
    	}
    	
    	//2.Generate DAG
    	n=letters.size();
    	actualTopo.resize(n);
    	for(int i=0; i<s2.size(); i+=4){
    		u=s2[i]-'A';
    		v=s2[i+2]-'A';
    		adjList[u].push_back(v);
    		inDegree[v]++;
    	}
    	
    	//3.From each source, toposort
    	for(int i=0; i<=27; i++){
    		if(inDegree[i]==0){
    			topoSort(i, 0);
    		}
    	}
    	
    	//4.Print answer
    	if(strings.size()>0){
    		for(auto str : strings){
    			for(int i=0; i<str.size(); i++){
    				cout << str[i] << " \n"[i==str.size()-1];
    			}
    		}
    	}
    	else{
    		cout << "NO\n";
    	}
    }
    return 0;
}
