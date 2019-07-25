#include <stdio.h>
int main(){
	long long a, b, c;
	long long q;
	scanf("%lld", &q);
	while(q--){
		scanf("%lld%lld%lld", &a, &b, &c);
		long long ans=a+b+c;
		ans/=2;
		printf("%lld\n", ans);
	}
	return 0;
}