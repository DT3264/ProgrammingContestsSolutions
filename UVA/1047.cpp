#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
using namespace std;
template<class T>
using v=vector<T>;
int getMatch(v<int> &v1, const v<bool> &v2){
	int match=0;
	for(int i=0; i<v1.size(); i++){
		if(v1[i] && v2[i]){
			match++;
		}
	}
	return match;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
	int n, m;
	int actCase=1;
    while(cin >> n >> m && n+m>0){
    	v<int> vec(n);
    	map<v<bool>, int> intersections;
    	
    	for(auto &x : vec) cin >> x;
    	
    	int intersectCount;
		int poles, pole, intersectP;
    	cin >> intersectCount;
    	for(int i=0; i<intersectCount; i++){
    		v<bool> actIntersect(n, 0);
    		cin >> poles;
    		while(poles--){
    			cin >> pole;
    			actIntersect[pole-1]=1;
    		}
    		cin >> intersectP;
    		intersections[actIntersect]+=intersectP;
    	}
    	
    	v<int> actPermu(n, 0);
    	for(int i=0; i<m; i++){
    		actPermu[i]=1;
    	}
    	
    	int bestAns=0;
    	v<int> bestPermu;
    	do{
    		int actAns=0;
    		for(int i=0; i<vec.size(); i++){
    			if(actPermu[i]) actAns+=vec[i];
    		}
    		for(auto &p : intersections){
    			int match=getMatch(actPermu, p.first);
    			if(match>0){
    				actAns-=(match-1)*p.second;
    			}
    		}
    		if(actAns>bestAns){
    			bestAns=actAns;
    			bestPermu=actPermu;
    		}
    		bestAns=max(bestAns, actAns);
    	}while(prev_permutation(actPermu.begin(), actPermu.end()));
    	
    	cout << "Case Number  " << actCase++ << '\n';
    	cout << "Number of Customers: " << bestAns << '\n';
    	cout << "Locations recommended: ";
    	int numCount=0;
    	for(int i=0; i<n;  i++){
    		if(bestPermu[i]) cout << i+1 << (numCount++!= m-1 ? ' ' : '\n');
    	}
    	cout << '\n';
    }
    return 0;
}
