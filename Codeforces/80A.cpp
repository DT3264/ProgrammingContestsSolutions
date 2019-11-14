#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n){
	int cont=0;
	for(int i=2; i<n; i++){
		if(n%i==0){
			cont++;
		}
	}	
	return cont==0;
}
int main(){
	int n, m, i;
	scanf("%d%d", &n, &m);
	bool is=isPrime(m);
	for(i=n+1; i<m; i++){
		if(isPrime(i)){
			is=false;
		}
	}
	printf("%s\n", (is ? "YES" : "NO"));
}