#include<bits/stdc++.h>
using namespace std;
int main(){
	string s, nS;
	cin >> s;
	int i, cont=0;
	bool can=true;
	for(i=0; i<s.length() && can; i++){
		if(s[i]=='4' or s[i]=='7'){
			cont++;
		}
	}
	nS=to_string(cont);
	cont=0;
	for(i=0; i<nS.length(); i++){
		if(nS[i]!='4' && nS[i]!='7'){
			can=false;
		}
	}
	printf("%s\n", (can ? "YES" : "NO"));
}