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
int n, m;
v<int> vec;
bool parte(int cap){
	int l=0, r=0;
	int actSum=0, actVes=1;
	for(auto &x : vec){
		if(x>cap) return false;
		if(x+actSum>cap){
			actSum=0;
			actVes++;
			if(actVes>m) return false;
		}
		actSum+=x;
	}
	return true;
}
int main(){
    // printDebug=true;
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    while(cin >> n >> m){
    	vec=v<int>(n);
    	for(auto &x : vec) cin >> x;
    	int l=0;
    	int r=1e9;
    	int bestAns;
    	while(l<=r){
    		debug cout << l << " && " << r << '\n';
    		int mid=(l+r)/2;
    		debug cout << "Mid: " << mid << '\n';
    		if(parte(mid)){
    			bestAns=mid;
    			r=mid-1;
    		}
    		else{
    			l=mid+1;
    		}
    	}
    	cout << bestAns << '\n';
    }
    return 0;
}
