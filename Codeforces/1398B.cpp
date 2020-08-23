
// Problem : B. Substring Removal Game
// Contest : Codeforces - Educational Codeforces Round 93 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1398/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define y1 yy
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
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
    	string str;
    	cin >> str;
    	vector<int> vec;
    	int consecOnes=0;
    	for(char &c : str){
    		if(c=='1') consecOnes++;
    		else{
    			if(consecOnes>0){
    				vec.push_back(consecOnes);
    				consecOnes=0;
    			}
    		}
    	}
    	if(consecOnes>0){
    		vec.push_back(consecOnes);
    		consecOnes=0;
    	}
    	sort(vec.rbegin(), vec.rend());
    	int ans=0;
    	for(int i=0; i<vec.size(); i+=2) ans+=vec[i];
    	cout << ans << "\n";
    }
    return 0;
}
