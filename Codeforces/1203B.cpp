#include<stdio.h>
#include<algorithm>
int main(){
	int q;
	int arr[400];
	scanf("%d", &q);
	while(q--){
		int n, i;
		scanf("%d", &n);
		for(i=0; i<n*4; i++){
			scanf("%d", &arr[i]);
		}
		std::sort(arr, arr+(n*4));
		bool can = true;
		for(i=0; i<n*4; i+=2){
			if(arr[i]!=arr[i+1]){
				can=false;
			}
		}
		int lPos = 0, rPos = (n*4)-1;
		int area = arr[lPos]*arr[rPos];
		for(i=0; i<n; i++){
			if(arr[lPos]*arr[rPos] != area){
				can=false;
			}
			lPos+=2;
			rPos-=2;
		}
		printf("%s\n", (can ? "YES" : "NO"));
	}
}