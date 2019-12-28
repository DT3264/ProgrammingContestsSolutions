#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, a, b, c, r;
	int ans;
	cin >> n;
	while(n--){
		ans=0;
		cin >> a >> b >> c >> r;
		if(a>b){
			swap(a, b);
		}
		int x1 = c-r;
		int x2 = c+r;
		if(x2<a || x1>b){
			ans=b-a;
		}
		else if(x1>=a && x2>b){
			ans = x1-a;
		}
		else if(x1>=a && x2<=b){
			ans = (x1-a)+(b-x2);
		}
		else if(x1<a && x2<=b){
			ans = b-x2;
		}
		cout << ans << endl;
	}
	return 0;
}