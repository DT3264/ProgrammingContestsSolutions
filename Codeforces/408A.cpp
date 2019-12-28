#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, i, j, t, arr[100];
	cin >> n;
	for(i=0; i<n; i++){
		cin >> arr[i];
	}
	int ans=1000000000;
	for(i=0; i<n; i++){
		int actCash=0;
		for(j=0; j<arr[i]; j++){
			cin >> t;
			actCash+=(t*5)+15;
		}
		ans=min(ans, actCash);
	}
	cout << ans << endl;
	return 0;
}
