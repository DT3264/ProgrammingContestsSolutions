#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	double a, t=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		cin >> a;
		t+=1/a;
	}
	cout << 1/t << "\n";
}
