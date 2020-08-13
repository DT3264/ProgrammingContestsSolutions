
// Problem : A. Boboniu Likes to Color Balls
// Contest : Codeforces - Codeforces Round #664 (Div. 2)
// URL : https://codeforces.com/contest/1395/problem/0
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
    	int pares=0;
    	int mq0=0;
    	vector<int> vec(4);
    	for(int &x : vec){
    		cin >> x;
    		pares+=(x%2==0);
    		mq0+=x>0;
    	}
    	bool can=pares>=3 || mq0==1;
    	vec[0]--;
    	vec[1]--;
    	vec[2]--;
    	if(vec[0]>=0 && vec[1]>=0 && vec[2]>=0){
    		vec[3]+=3;
    		pares=0;
    		mq0=0;
    		for(int &x : vec){
    			pares+=(x%2==0);
    			mq0+=x>0;
    		}
    		if(pares>=3 || mq0==1) can=true;
    	}
    	cout << (can ? "Yes" : "No") << "\n";
    }
    return 0;
}
