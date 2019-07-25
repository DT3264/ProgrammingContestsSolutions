#include <stdio.h>
#include <vector>
#define ll long long
using namespace std;
int main(){
	ll q, i;
	ll n, k;
	ll arr[200001];
	scanf("%lld", &q);
	while(q--){
		vector<int> ans;
		ll sum=0;
		ll cont=0;
		scanf("%lld%lld", &n, &k);
		for(i=0; i<n; i++){
			scanf("%lld", &arr[i]);
			sum+=arr[i];
			if(sum%2!=0 && cont<k-1){
				ans.push_back(i+1);
				sum=0;
				cont++;
			}
		}
		if(sum%2!=0){
			cont++;
			ans.push_back(n);
		}
		if(cont==k){
			printf("YES\n");
			for(i=0; i<ans.size(); i++){
				printf("%d ", ans[i]);
			}
		}
		else{
			printf("NO");
		}
		printf("\n");
	}
	return 0;
}