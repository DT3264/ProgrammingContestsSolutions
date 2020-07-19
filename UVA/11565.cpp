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
int a, b, c;
bool can(int i, int j, int k){
	return i+j+k==a && i*j*k==b && (i*i)+(j*j)+(k*k)==c;
}
void printAns(int i, int j, int k){
	vector<int> ans={i, j, k};
	sort(ans.begin(), ans.end());
	for(int ind=0; ind<3; ind++){
		cout << ans[ind];
		if(ind<2) cout << " ";
	}
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases;
    bool found;
    cin >> cases;
    while(cases--){
    	found=false;
    	cin >> a >> b >> c;
    	for(int i=1; i<=100; i++){
    		for(int j=i+1; j<=100; j++){
    			for(int k=j+1; k<=100; k++){
    				if(can(-i, -j, k)){
    					printAns(-i, -j, k);
    					i=101, j=101, k=101;
    					found=true;
    				}
    				else if(can(i, j, k)){
    					printAns(i, j, k);
       					i=101, j=101, k=101;
    					found=true;
    				}
    			}
    		}
    	}
    	cout << (found ? "" : "No solution.") << "\n";
    }
    return 0;
}
