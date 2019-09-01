#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct goal{
	ll cant;
	vector<ll> div;
};
goal goals[200001];
int main(){
	ll n, k, i, j, arr[200001];
	ll ans=100000000000000, aAns;
	scanf("%I64d%I64d", &n, &k);
	for(i=0; i<n; i++){
		scanf("%I64d", &arr[i]);
	}
	sort(arr, arr+n);
	for(i=0; i<n; i++){
		ll actI=arr[i];
		ll divCont=0;
		while(actI>0){
			goals[actI].cant++;
			goals[actI].div.push_back(divCont++);
			actI=floor((double)actI/(double)2);
		}
	}
	goal *aGoal;
	for(i=0; i<200001; i++){
		aGoal=&goals[i];
		if(aGoal->cant>=k){
			//printf("Can reach %I64d with %I64d nums and %I64d divisors\n", i, aGoal->cant, aGoal->div.size());
			aAns=0;
			for(j=0; j<k; j++){
				//printf("+ %I64d ", aGoal->div[j]);
				aAns+=aGoal->div[j];
			}
			//printf("\n");
			ans=min(ans, aAns);
		}
	}
	printf("%I64d\n", ans);
}