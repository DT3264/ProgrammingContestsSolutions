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
vector<int> vec;
vector<int> ans(6, 0);
void comb(int posArr, int posAns){
	if(posAns==6){
		for(int i=0; i<ans.size(); i++)
		cout << ans[i] << " \n"[i==ans.size()-1];
		return;
	}
	for(int i=posArr; i<vec.size(); i++){
		ans[posAns]=vec[i];
		comb(i+1, posAns+1);
	}
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int n;
    int actCase=1;
    while(cin >> n){
    	if(n==0) break;
    	if(actCase++>1) cout << "\n";
    	vec.resize(n);
    	for(int &x : vec) cin >> x;
    	comb(0, 0);
    }
    return 0;
}
