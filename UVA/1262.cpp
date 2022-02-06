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
v<v<char>> matches;
int permuCount;
int n;
v<char> actAns(5), ans(5);
void permuta(int pos){
	if(permuCount==n) return;
	if(pos==5){
		permuCount++;
		if(permuCount==n){
			ans=actAns;
		}
		return;
	}
	for(int i=0; i<matches[pos].size(); i++){
		actAns[pos]=matches[pos][i];
		permuta(pos+1);
	}
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    // printDebug=true;
    int cases;
    cin >> cases;
    while(cases--){
    	cin >>n;
    	v<string> g1(6), g2(6);
    	for(auto &s : g1) cin >> s;
    	for(auto &s : g2) cin >> s;
    	matches=v<v<char>>(5, v<char>());
    	for(int i=0; i<5; i++){
    		debug cout << "Col: " << i << '\n';
    		map<char, int> count;
    		set<char> s1, s2;
    		for(int j=0; j<6; j++){
    			debug cout << g1[j][i] << " & " << g2[j][i] << '\n';
    			s1.insert(g1[j][i]);
    			s2.insert(g2[j][i]);
    			// count[g1[j][i]]++;
    			// count[g2[j][i]]++;
    		}
    		for(auto c : s1) count[c]++;
    		for(auto c : s2) count[c]++;
    		for(auto &p : count){
    			if(p.s==2){
    				debug cout << p.f << ' ';
    				matches[i].push_back(p.f);
    			}
    		}
    		debug cout << '\n';
    	}
    	permuCount=0;
    	permuta(0);
    	if(permuCount==n){
    		for(int i=0; i<5; i++){
    			cout << ans[i];
    		}
    		cout << '\n';
    	}
    	else{
    		cout << "NO\n";
    	}
    }
    return 0;
}
