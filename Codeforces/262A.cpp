#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, k, a, ans=0;
	cin >> n >> k;
	while(n--){
		int luckCount=0;
		cin >> a;
		while(a>0){
			if(a%10 == 4 || a%10 == 7){
				luckCount++;
			}
			a/=10;
		}
		if(luckCount<=k){
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
