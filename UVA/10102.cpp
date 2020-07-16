#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define si set<int>
#define y1 yy
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
int dist(pii &p1, pii &p2){
	return  abs(p1.f-p2.f)+abs(p1.s-p2.s);
}
int main(){
    //printDebug=true;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int n;
    while(cin >> n){
   		vector<string> vec(n);
   		vector<pii> start, end;
   		for(int i=0; i<vec.size(); i++){
   			cin >> vec[i];
   			for(int j=0; j<vec[i].size(); j++){
   				if(vec[i][j]=='1'){
   					start.push_back({i, j});
   				}
   				if(vec[i][j]=='3'){
   					end.push_back({i, j});
   				}
   			}
   		}
   		int ans=0;
   		map<int, int> mapa;
   		for(auto &s : start){
   			int localAns=1e9;
   			for(auto &e : end){
   				localAns=min(localAns, dist(s, e));
   			}
   			ans=max(ans, localAns);
   		}
   		cout << ans << "\n";
    }
    return 0;
}
