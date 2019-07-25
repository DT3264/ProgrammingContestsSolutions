#include <stdio.h>
#include <vector>
#define ll long long
using namespace std;
char str[20001];
char rgb[3]={'R', 'G', 'B'};
int solve(int i, int n, int pos){
	int cont=0;
	//printf("from %d to %d\n", i, n);
	for(i=i; i<=n; i++){
		if(str[i]!=rgb[pos%3]){
			cont++;
		}
		pos++;
	}
	return cont;
}
 
int main(){
	int q, i;
	int n, k;
	scanf("%lld", &q);
	while(q--){
		scanf("%d%d", &n, &k);
		scanf("%s", str);
		int ans=100000000;
		for(i=0; i+k-1<n; i++){
			ans=min(ans, solve(i, i+k-1, 0));
			ans=min(ans, solve(i, i+k-1, 1));
			ans=min(ans, solve(i, i+k-1, 2));
		}
		printf("%d\n", ans);
	}
	return 0;
}