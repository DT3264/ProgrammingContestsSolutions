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
    	vector<int> vec(2*n);
    	vector<bool> used(n+1, 0);
    	vector<int> ans;
    	for(int &x : vec){
    		cin >> x;
    		if(!used[x]){
    			used[x]=1;
    			ans.push_back(x);
    		}
    	}
    	for(int &x : ans){
    		cout << x << " ";
    	}
    	cout << "\n";
    }
    return 0;
}
