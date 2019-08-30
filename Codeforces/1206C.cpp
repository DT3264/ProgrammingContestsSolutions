#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[200003];
int n;
int main(){
	vector<ll> sum;
	int i;
	scanf("%d", &n);
	bool toLeft=false;
	ll aPos=1;
	int left=0, right=n;
	arr[left++]=aPos++;
	while(aPos<=n*2){
		if(toLeft){
			arr[left++]=aPos++;
			arr[left++]=aPos++;
		}
		else{
			arr[right++]=aPos++;
			arr[right++]=aPos++;
		}
		toLeft=!toLeft;
	}
	ll lastSum=0;
	ll actualSum=0;
	bool can=true;
	for(i=0; i<n; i++){
		lastSum+=arr[i];
	}
	actualSum=lastSum;
	for(i=1; i<n*2; i++){	
		actualSum-=arr[i-1];
		actualSum+=arr[(n+i-1)%(2*n)];
		if(abs(actualSum-lastSum>1)){
			can=false;
		}
		lastSum=actualSum;
	}
	if(can){
		printf("YES\n");
		for(i=0; i<n*2; i++){
			cout << arr[i] << " ";
		}
		printf("\n");
	}
	else{
		printf("NO\n");
	}
}