#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, i;
	string str;
	cin >> n;
	while(n--){
		int sum=0;
		bool exist0=false;
		int existEven=false;
		cin >> str;
		for(i=0; i<str.length(); i++){
			sum+=str[i]-'0';
			if(str[i]=='0' && !exist0){
				exist0=true;
			}
			else if((str[i]-'0')%2==0){
				existEven=true;
			}
		}
		//cout << sum << " - " << exist0 << " - " << existEven << endl;
		if(sum%3==0 && exist0 && existEven){
			cout << "red\n";
		}
		else{
			cout << "cyan\n";
		}
	}
}