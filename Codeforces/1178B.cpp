#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll arr[1000001];
int main(){
	ll i, j, k, l, m, cont=0;
	string s;
	cin >> s;
	ll consecVs=0;
	for(i=s.length()-1; i>0; i--){
		if(s[i]=='v' && s[i-1]=='v'){
			consecVs++;
		}
		arr[i]=consecVs;
	}
	arr[0]=consecVs;
	ll totalVs=consecVs;
	for(i=0; i<s.length(); i++){
		if(s[i]=='o'){
			ll toLeft=totalVs-arr[i];
			ll toRight=arr[i];
			cont+=toLeft*toRight;
		}
	}
	cout << cont << "\n";
	return 0;
}