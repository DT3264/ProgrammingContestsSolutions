
// Problem : D. Decrease the Sum of Digits
// Contest : Codeforces - Codeforces Round #667 (Div. 3)
// URL : https://codeforces.com/contest/1409/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define y1 yy
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
int getSumOfNum(string &num){
	int sum=0;
	for(char &c : num){
		sum+=c-'0';
	}
	return sum;
}

void propagateChange(string &num, int pos){
	num[pos]='0';
	if(pos-1>=0){
		num[pos-1]++;
		if(num[pos-1]>'9'){
			propagateChange(num, pos-1);
		}
	}
	else{
		num="1"+num;
	}
}

void setNextTo0(string &num){
	for(int i=num.size()-1; i>=0; i--){
		if(num[i]>'0'){
			propagateChange(num, i);
			return;
		}
	}
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	string num;
    	int s;
    	cin >> num >> s; 
    	ll startNum=stoll(num);
    	int actSum=getSumOfNum(num);
    	while(actSum>s){
    		setNextTo0(num);
    		actSum=getSumOfNum(num);
    		//cout << "ActSum: " << actSum << "\n";
    	}
    	ll lastNum=stoll(num);
    	cout << lastNum-startNum << "\n";
    }
    return 0;
}
