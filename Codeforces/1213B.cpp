#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, q, i, arr[150000];
	scanf("%d", &q);
	int minN;
	int ans;
	while(q--){
		scanf("%d", &n);
		for(i=0; i<n; i++){
			scanf("%d", &arr[i]);
		}
		minN=arr[n-1];
		ans=0;
		for(i=n-2; i>=0; i--){
			if(arr[i]>minN){
				ans++;
			}
			minN=min(minN, arr[i]);
		}
		printf("%d\n", ans);
	}
}