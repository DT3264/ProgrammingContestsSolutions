
// Problem : 200 - Rare Order
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=136
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
v<string> vec;
v<int> adjList[28];
bool visited[28];
bool exists[28];
v<char> ans;
void dfs(int pos){
	visited[pos]=1;
	for(int &x : adjList[pos]){
		if(!visited[x]) dfs(x);
	}
	ans.push_back(pos+'A');
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    while(cin >> str && str!="#"){
    	vec.push_back(str);
    	for(auto &c : str){
    		exists[c-'A']=1;
    	}
    }
    for(int i=1; i<vec.size(); i++){
    	string s1=vec[i-1];
    	string s2=vec[i];
    	for(int j=0; j<min(s1.size(), s2.size()); j++){
    		if(s1[j]!=s2[j]){
    			adjList[s1[j]-'A'].push_back(s2[j]-'A');
    			j=max(s1.size(), s2.size());
    		}
    	}
    }
    for(int i=0; i<=27; i++){
    	if(exists[i] && !visited[i]){
    		dfs(i);
    	}
    }
    reverse(ans.begin(), ans.end());
    for(auto &c : ans) cout << c;
    cout << "\n";
    return 0;
}
