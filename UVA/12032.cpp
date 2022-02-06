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
v<int> vec;
int n;
bool test(int x){
	for(int i=1; i<n; i++){
		int val=abs(vec[i]-vec[i-1]);
		if(val>x) return false;
		if(val==x) x--;
	}
	return true;
}
int main(){
    // printDebug=true;
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int cases;
    cin >> cases;
    int actCase=1;
    while(cases--){
    	cin >> n;
    	n++;
    	vec=v<int>(n);
    	vec[0]=0;
    	for(int i=1; i<n; i++) cin >> vec[i];
    	int l=1, r=1e9;
    	int ans=0;
    	while(l<=r){
    		int mid=(l+r)/2;  
    		if(test(mid)){
    			ans=mid;
    			r=mid-1;
    		}  		
    		else{
    			l=mid+1;
    		}
    	}
    	printf("Case %d: %d\n", actCase++, ans); 
    }
    return 0;
}
