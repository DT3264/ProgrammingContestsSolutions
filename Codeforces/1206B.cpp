#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool sortByAbs(const ll &a, const ll &b){
	return abs(a)<abs(b);
}
int main(){
	ll arr[100000];
	ll n, i, cont=0;
	ll neg=0;
	scanf("%I64d", &n);
	for(i=0; i<n; i++){
		scanf("%I64d", &arr[i]);
		if(arr[i]<0){
			neg++;
			cont+=abs(arr[i])-1;
			arr[i]=-1;
		}
		else if(arr[i]>0){
			cont+=arr[i]-1;
			arr[i]=1;
		}
	}
	sort(arr, arr+n, sortByAbs);
	for(i=0; i<n; i++){
		if(arr[i]==0){
			cont++;
			if(neg%2!=0){
				neg++;
			}
		}
		else if(arr[i]==-1){
			if(neg%2!=0){
				//From -1 to 1
				neg--;
				cont+=2;
			}
		}
		else{
			//From -1 to 1
			if(neg%2!=0){
				neg++;
				cont+=2;
			}
		}
	}
	printf("%I64d", cont);
	
}