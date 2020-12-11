
// Problem : 459 - Graph Connectivity
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=400
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
v<set<int>> vec;
vi visited;
void dfs(int pos){
	visited[pos]=1;
	for(int x : vec[pos]){
		if(!visited[x]) dfs(x);
	}
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    /*noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);*/
    int cases;
    string str;
    cin >> cases;
    cin.ignore();
    vector<string> lines;
    while(getline(cin, str)) lines.push_back(str);
    int pos=0;
    while(cases--){
    	pos+=2;
    	vec=v<set<int>>(28);
    	visited=vi(28,0);
    	for(int i='A'; i<=lines[pos-1][0]; i++){
    		int u=i-'A';
    		vec[u].insert(u);
    	}
    	while(pos<lines.size() && lines[pos].size()>0){
    		str=lines[pos];
    		int u=str[0]-'A';
    		int v=str[1]-'A';
    		vec[u].insert(v);
    		vec[v].insert(u);
    		pos++;
    	}
    	int groups=0;
    	for(int i=0; i<vec.size(); i++){
    		if(vec[i].size()>0 && !visited[i]){
    			groups++;
    			dfs(i);
    		}
    	}
    	cout << groups << "\n" << (cases>0 ? "\n": "");
    }
    return 0;
}
