#include<bits/stdc++.h>
using namespace std;
int main(){
	int i, j;
	string s;
	cin >> s;
	for(i=s.length()-1; i>=0; i--){
		int num = s[i]-'0';
		bool lessThan5=num<5;
		if(num>=5){
			num-=5;
		}
		if(lessThan5){
			cout << "O-|";
		}
		else{
			cout << "-O|";
		}
		for(j=0; j<5; j++){
			cout << (j==num ? '-' : 'O');
		}
		cout << "\n";
	}
}