
// Problem : 193 - Graph isBlacking
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=129
// Memory Limit : 32 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define si set<int>
#define y1 yy
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
vector<vector<int>> adjList;
vector<bool> isBlack;
int countBlackBest;
vector<bool> recurrAns;
int n, k;
bool canBeBlack(int i){
	for(int &x : adjList[i]){
		if(isBlack[x]) return false;
	}
	return true;
}
void paint(int pos, int countBlack){
	if(pos==n+1){
		if(countBlack>countBlackBest){
			countBlackBest=countBlack;
			recurrAns=isBlack;
		}
		return;
	}
	if(canBeBlack(pos)){
		isBlack[pos]=1;
		paint(pos+1, countBlack+1);
	}
	isBlack[pos]=0;
	paint(pos+1, countBlack);
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	cin >> n >> k;
    	countBlackBest=0;
    	recurrAns.assign(n+1, false);
    	isBlack.assign(n+1, 0);
    	adjList=vector<vector<int>>(n+1);
    	int u, v;
    	for(int i=0; i<k; i++){
    		cin >> u >> v;
    		adjList[u].push_back(v);
    		adjList[v].push_back(u);
    	}
    	paint(1, 0);
    	vector<int> ans;
    	for(int i=1; i<=n; i++){
            if(recurrAns[i]) ans.push_back(i);
    	}
    	cout << ans.size() << "\n";
    	for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " \n"[i==ans.size()-1];
    	}
    }
    return 0;
}
