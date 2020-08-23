
// Problem : 11057 - Exact Sum
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1998
// Memory Limit : 32 MB
// Time Limit : 3000 ms
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
bool find(int pos, int price, vector<int> &vec){
	int l=0, r=pos-1;
	while(l<=r){
		int mid=(l+r)/2;
		int sum=vec[pos]+vec[mid];
		if(sum==price){
			return true;
		}
		else if(sum>price){
			r=mid-1;
		}
		else if(sum<price){
			l=mid+1;
		}
	}
	return false;
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int n;
    while(cin >> n){
    	int price;
    	pair<int, int> ans={-1, -1};
    	vector<int> vec(n);
    	for(int &x : vec) cin >> x;
    	cin >> price;
    	sort(vec.begin(), vec.end());
    	for(int i=n-1; i>=0; i--){
    		if(find(i, price, vec)){
    			ans.f=price-vec[i];
    			ans.s=vec[i];
    		}
    	}
    	cout << "Peter should buy books whose prices are " << ans.f << " and " << ans.s << ".\n\n";
    }
    return 0;
}
