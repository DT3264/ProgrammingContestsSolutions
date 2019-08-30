#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, i;
	double arr[50];
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	double ans=arr[0];
	for(i=1; i<n; i++){
		ans=(ans+arr[i])/2;
	}
	cout << ans << "\n";
}
