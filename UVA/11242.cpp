#include<bits/stdc++.h>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
int main(){
    //printDebug=true;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int n, m;
    while(cin >> n){
    	if(n==0) break;
    	cin >> m;
    	vector<double> num;
    	vector<double> front(n);
    	for(double &f : front) cin >> f;
    	vector<double> rear(m);
    	for(double &r : rear){
    		cin >> r;
    		for(double &f : front){
    			num.push_back(r/f);
    		}
    	}
		sort(num.begin(), num.end());
		double ans=0;
    	for(int i=1; i<num.size(); i++){
    		ans=max(ans, num[i]/num[i-1]);
    	}
 		cout << fixed << setprecision(2) << ans << "\n";
    	
    }
    return 0;
}
