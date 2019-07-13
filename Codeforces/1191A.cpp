#include "bits/stdc++.h"
using namespace std;
char getCategory(int n){
	if(n%4==1){
		return 'A';
	}
	if(n%4==3){
		return 'B';
	}
	if(n%4==2){
		return 'C';
	}
	if(n%4==0){
		return 'D';
	}
}
int main() {
	int n;
	cin >> n;
	char nextCategory;
	char bestCategory=getCategory(n);
	int bestN=n;
	for(int i=1; i<=2; i++){
		nextCategory=getCategory(n+i);
		if(nextCategory<bestCategory){
			bestCategory=nextCategory;
			bestN=n+i;
		}
	}
	cout << bestN-n << " " << bestCategory << "\n";
	return 0;
}