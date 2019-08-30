#include<bits/stdc++.h>
using namespace std;
int main(){
	int arr1[200], arr2[200];
	map<int, bool> nums;
	int n, m, i, j;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &arr1[i]);
		nums[arr1[i]]=true;
	}
	scanf("%d", &m);
	for(i=0; i<m; i++){
		scanf("%d", &arr2[i]);
		nums[arr2[i]]=true;
	}
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if(!nums[arr1[i]+arr2[j]]){
				printf("%d %d\n", arr1[i], arr2[j]);
				i=n;
				j=m;
			}
		}
	}
}