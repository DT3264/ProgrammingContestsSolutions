
// Problem : C. Random Events
// Contest : Codeforces - Codeforces Round #689 (Div. 2, based on Zed Code Competition)
// URL : https://codeforces.com/contest/1461/problem/C
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
#define noDebug if(!printDebug)
using namespace std;
template<class T>
using v=vector<T>;   
bool printDebug=false;
struct Prob{
	int i;
	double p;
};
int checkVec(vi &vec){
	int toRet=-1;
	for(int i=0; i<vec.size(); i++){
		if(vec[i]!=i+1) toRet=max(toRet, vec[i]);
	}
	return toRet;
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    int cases;
    int n, m;
    cin >> cases;
    while(cases--){
    	cin >> n >> m;
    	vi vec=vi(n);
    	v<Prob> prob(m);
    	for(int &x : vec) cin >> x;
    	int sortedTo=checkVec(vec);
    	int nP;
    	double pP;
    	double ans=1.0;
    	for(int i=0; i<m; i++){
    		cin >> nP >> pP;
    			if(nP>=sortedTo) ans*=(1.0-pP);
    	}
    	if(sortedTo==-1) ans=0.0;
    	cout << fixed << setprecision(6) << 1.0-ans << "\n";
    }
    return 0;
}
