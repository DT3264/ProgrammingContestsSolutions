#include <bits/stdc++.h>
using namespace std;
int main(){
	int i, n, arr[100];
	int rInd=0;
	int left=0, right=0;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
		right+=arr[i];
	}
	int ans=100000;
	while(rInd<n){
		ans=min(ans, abs(left-right));
		//printf("actual ans: %d-%d: %d\n", left, right, left-right);
		left+=arr[rInd];
		right-=arr[rInd++];
	}
	printf("%d\n", ans);
}
