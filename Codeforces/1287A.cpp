#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, sLen, i, ans;
	string s;
	cin >> n;
	while(n--){
		ans=0;
		int consecP=-1;
		cin >> sLen >> s;
		for(i=0; i<sLen; i++){
			if(s[i]=='A'){
				ans=max(consecP, ans);
				consecP=0;
			}
			else{
				if(consecP!=-1){
					consecP++;
				}
			}
		}	
		ans=max(consecP, ans);
		cout << ans << endl;
	}
	return 0;
}