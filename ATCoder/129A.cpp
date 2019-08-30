#include <bits/stdc++.h>
using namespace std;
int main(){
	int p, q, r;
	scanf("%d%d%d", &p, &q, &r);
	int ans=100000000;
	ans=min(ans, p+q);
	ans=min(ans, q+r);
	ans=min(ans, r+p);
	printf("%d\n", ans);
}
