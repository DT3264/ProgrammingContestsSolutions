#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, t, i, par=0, impar=0;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &t);
		if(t%2==0){
			par++;
		}
		else{
			impar++;
		}
	}
	int ans=min(par, impar);
	printf("%d\n", ans);
}