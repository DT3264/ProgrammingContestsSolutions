
// Problem : C. Fox And Names
// Contest : Codeforces - Codeforces Round #290 (Div. 2)
// URL : http://codeforces.com/problemset/problem/510/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int n;
    string s1, s2;
	v<vi> adjList(27);
	vi inDegree(27, 0);
    string ans;
    bool can=true;
    cin >> n;
    cin >> s1;
    for(int i=0; i<n; i++){
    	cin >> s2;
    	for(int j=0; j<min(s1.size(), s2.size()); j++){
    		if(s1[j]!=s2[j]){
    			int u=c2i(s1[j]);
    			int v=c2i(s2[j]);
    			adjList[u].push_back(v);
    			inDegree[v]++;
    			j=max(s1.size(), s2.size());
    		}
    		if(s1.size()>s2.size() && j==s2.size()-1) can=false;
    	}
    	s1=s2;
    }
    while(can){
	    if(ans.size()==26) break;
	    for(int i=0; i<26; i++){
	    	if(inDegree[i]==0){
	    		ans+=i2c(i);
	    		for(auto &v : adjList[i]) inDegree[v]--;
	    		inDegree[i]=-1;
	    		i=26;
	    	}
	    	if(i==25) can=false;
	    }
    }
    if(can) cout << ans << "\n";
    else cout << "Impossible" << "\n";
    return 0;
}
