#include<bits/stdc++.h>
using namespace std;
int arr1[2], arr2[2];
int main(){
	int n, i;
	int n1, n2;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d%d", &n1, &n2);
		arr1[0]+=n1%2!=0;
		arr1[1]+=n1%2==0;
		arr2[0]+=n2%2!=0;
		arr2[1]+=n2%2==0;
	}
	int min1=min(arr1[0], arr1[1]);
	int min2=min(arr2[0], arr2[1]);
	int ans=min1+min2;
	printf("%d\n", ans);
}