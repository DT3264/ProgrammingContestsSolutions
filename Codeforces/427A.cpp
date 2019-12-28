#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int cops=0, ans=0, t;
	cin >> n;
	while(n--){
        cin >> t;
        if(t==-1){
            if(cops==0){
                ans++;
            }
            else{
                cops--;
            }
        }
        else{
            cops+=t;
        }
	}
	cout << ans << "\n";
	return 0;
}
