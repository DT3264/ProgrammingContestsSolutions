#include<bits/stdc++.h>
int main(){
	int arr[100000];
	int n, i;
	bool can=true;
	scanf("%d", &n);
	scanf("%d", &arr[0]);
	for(i=1; i<n; i++){
		scanf("%d", &arr[i]);
		//printf("%d ", arr[i]);
		if(arr[i]-arr[i-1]<0){
			can=false;
		}
		if(arr[i]-arr[i-1]>0){
			arr[i]--;
		}
	}
	printf("%s\n", (can ? "Yes" : "No"));
}
