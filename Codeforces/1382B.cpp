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
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	int n;
    	cin >> n;
    	vi vec(n);
    	bool iMoved=false;    	
    	for(int &x : vec) cin >> x;
    	for(int &x : vec){
    		iMoved=!iMoved;
    		if(x!=1) break;
    	}
    	cout << (iMoved ? "First" : "Second") << "\n";
    }
    return 0;
}
