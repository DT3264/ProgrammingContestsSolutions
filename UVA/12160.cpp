#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
bool printDebug=false;
using namespace std;
template<class T>
using v=vector<T>;
int main(){
    // printDebug=true;
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int l, r, n;
    int actCase = 1;
    while((cin>> l >> r >> n) && l+r+n > 0){
    	int ans = -1;
    	v<int> vec(n);
    	for(auto &x : vec) cin >> x;
    	queue<pii> q;
    	map<int, bool> visited;
    	q.push({l, 0});
    	visited[l] = 1;
    	while(!q.empty()){
    		auto act = q.front();
    		q.pop();
    		if(ans != -1) continue;
    		// cout << "Con " << act.f << endl;
    		for(auto &x : vec){
    			int next = (act.f+x)%10000;
    			if(!visited[next]){
    				visited[next] = 1;
    				q.push({next, act.s+1});
    				if(next == r) ans = act.s+1;
    			}
    		}
    	}
    	if(ans == -1) printf("Case %d: Permanently Locked\n", actCase++);
    	else printf("Case %d: %d\n", actCase++, ans);
    }
    return 0;
}
