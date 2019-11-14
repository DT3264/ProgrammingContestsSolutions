#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int i, arr[100];
	int minN=101; 
	int maxN=0;
	int ans=0;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
		minN=min(minN, arr[i]);
		maxN=max(maxN, arr[i]);
	}
	int tmp;
	for(i=n-1; i>=0; i--){
		if(arr[i]==minN){
			break;
		}
	}
	for(i=i; i<n-1; i++){
		tmp=arr[i];
		arr[i]=arr[i+1];
		arr[i+1]=tmp;
		ans++;
	}
	
	for(i=0; i<n; i++){
		if(arr[i]==maxN){
			break;
		}
	}
	for(i=i; i>0; i--){
		tmp=arr[i];
		arr[i]=arr[i-1];
		arr[i-1]=tmp;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}