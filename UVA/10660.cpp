#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
using namespace std;
template<class T>
using v=vector<T>;
v<int> state;
v<int> bestState;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int cases, actCase=1;
    cin >> cases;
    while(cases--){
    	int n;
    	cin >> n;
    	v<v<int>> grid(5, v<int>(5));
    	v<pii> areas(n);
    	// Save each area
    	for(auto &p : areas){
    		cin >> p.f >> p.s >> grid[p.f][p.s];
    	}
    	int bestDistSum=1e9;
    	state=v<int>(25, 0);
    	for(int i=0; i<5; i++) state[i]=1;
    	// Start with permutation 1,1,1.....0,0,0
    	do{
    		int actDistSum=0;
    		// Get offices at actual state
    		v<pii> offices;
    		for(int i=0; i<25; i++){
    			if(state[i]){
    				int x=i/5;
    				int y=i%5;
    				offices.push_back({x, y});
    			}
    		}
    		// Get min distance to all areas
    		for(auto &a : areas){
    			int minDist=1e9;
    			// Get min distance to any office
    			for(auto &o : offices){
    				int population=grid[a.f][a.s];
    				int actDist=population*(abs(a.f-o.f)+abs(a.s-o.s));
    				minDist=min(actDist, minDist);
    			}
    			actDistSum+=minDist;
    		}
    		if(actDistSum<bestDistSum){
    			bestDistSum=actDistSum;
    			bestState=state;
    		}
    	}while(prev_permutation(state.begin(), state.end()));
    	int oC=0;
    	for(int i=0; i<25; i++){
    		if(bestState[i]) cout << i << " \n"[oC++==4];
    	}
    }
    return 0;
}
