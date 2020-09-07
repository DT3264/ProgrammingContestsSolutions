
// Problem : C. Yet Another Array Restoration
// Contest : Codeforces - Codeforces Round #667 (Div. 3)
// URL : https://codeforces.com/contest/1409/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
bool isValidVector(vi &vec){
	sort(vec.begin(), vec.end());
	for(int i=2; i<vec.size(); i++){
		if(vec[i]-vec[i-1]==vec[i-1]-vec[i-2]) continue;
		else return false;
	}
	return true;
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	int n, x, y;
    	vi divisores;
    	cin >> n >> x >> y;
    	int dist=y-x;
    	for(int i=1; i<=sqrt(dist); i++){
    		if(dist%i==0){
    			divisores.push_back(i);
    			if(dist/i>sqrt(dist) && dist/i<=dist){
    				divisores.push_back(dist/i);
    			}
    		}
    	}
    	sort(divisores.begin(), divisores.end());
    	vi bestVec={};
    	int minMax=1e9;
    	for(int &div : divisores){
    		vi actVec={x, y};
    		int remain=n-2;
    		int actN=x+div;
    		//fill the gapp
    		while(actN<y && remain>0){
    			actVec.push_back(actN);
    			actN+=div;
    			remain--;
    		}
    		actN=x-div;
    		//To the back
    		while(actN>=1 && remain>0){
    			actVec.push_back(actN);
    			actN-=div;
    			remain--;
    		}
    		//To the front
    		actN=y+div;
    		while(remain>0){
    			actVec.push_back(actN);
    			actN+=div;
    			remain--;
    		}
    		if(isValidVector(actVec) && actVec[n-1]<minMax){
    			minMax=actVec[n-1];
    			bestVec=actVec;
    		}
    	}
    	sort(bestVec.begin(), bestVec.end());
    	for(int &x : bestVec) cout << x << " ";
    	cout << "\n";
    }
    return 0;
}
