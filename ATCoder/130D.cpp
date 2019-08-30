 #include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll arr[100000];
	ll n, k, i;
	cin >> n >> k;
	for(i=0; i<n; i++){
		cin >> arr[i];
	}
	ll total=arr[0];
	ll left=0, right=1;
	ll ans=0;
	for(left=0; left<n; left++){
		//printf("Prev total: %d\n", total);
		while(total<k){
			if(right>=n){
				break;
			}
			total+=arr[right++];
		}
		if(total>=k){
			//printf("From: %d to %d\n", left, right);
			//printf("Ans+= %d-%d: %d\n", n, right, n-right+1);
			ans+=n-right+1;
		}
		total-=arr[left];
	}
	cout << ans << "\n";
}
