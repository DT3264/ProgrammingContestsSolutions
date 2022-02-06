#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define EPS 1e-7
#define debug if(printDebug)
bool printDebug=false;
using namespace std;
template<class T>
using v=vector<T>;
int p,q,r,s,t,u;
double eval(double x){
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
int main(){
    // printDebug=true;
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    while(cin >> p >> q >> r >> s >> t >> u){
    	double bestV=1e9;
    	double lastCalc=1e9;
    	double lB=0, rB=1;
    	while(lB+EPS<rB){
    		double mid=(lB+rB)/2;
    		if(eval(lB) * eval(mid) <= 0){
    			rB=mid;
    		}
    		else{
    			lB=mid;
    		}
    	}
    	double ans=(lB+rB)/2;
    	if(eval(0)*eval(1)>0) printf("No solution\n");
    	else printf("%.4lf\n", ans);
    }
    return 0;
}
