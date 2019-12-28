#include<bits/stdc++.h>
using namespace std;
int main(){
	int a, b, i;
	int w=0, d=0, l=0;
	cin >> a >> b;
	for(i=1; i<=6; i++){
		//cout << abs(i-a) << " " <<  abs(i-b) << endl;
		if(abs(i-a)<abs(i-b)){
			w++;
		}
		else if(abs(i-a)>abs(i-b)){
			l++;
		}
		else if(abs(i-a)==abs(i-b)){
			d++;
		}
	}
	cout << w << " " << d << " " << l << "\n";
	return 0;
}
