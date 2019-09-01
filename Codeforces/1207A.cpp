#include <bits/stdc++.h>
using namespace std;
int main(){
	int q;
	scanf("%d", &q);
	while(q--){
		int b, b1, b2;
		int p1, p2;
		int ans=0;
		scanf("%d%d%d", &b, &b1, &b2);
		scanf("%d%d", &p1, &p2);
		if(p1<p2){
			swap(p1, p2);
			swap(b1, b2);
		}
		while(b>=2 && b1>0){
			ans+=p1;
			b-=2;
			b1--;
		}
		while(b>=2 && b2>0){
			ans+=p2;
			b-=2;
			b2--;
		}
		printf("%d\n", ans);
	}
}