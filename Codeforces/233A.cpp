#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int i, arr[100];
	scanf("%d", &n);
	if(n%2!=0){
		printf("-1\n");
	}
	else{
		for(i=1; i<n; i+=2){
			printf("%d %d ", i+1, i);
		}
	}
	return 0;
}