
// Problem : C. Good String
// Contest : Codeforces - Educational Codeforces Round 92 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1389/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define si set<int>
#define y1 yy
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
bool nextStr(string &num){
	num[1]++;
	if(num[1]>'9'){
		num[1]='0';
		num[0]++;
		if(num[0]>'9'){
			return false;
		}
	}
	return true;
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	string str;
	 	string num="00";
	 	int bestLen=0;
	 	cin >> str;
	 	do{
	 		int localLen=0;
	 		bool numPos=0;
	 		int strPos=0;
	 		while(strPos<str.size()){
	 			if(str[strPos++]==num[numPos]){
	 				numPos=!numPos;
	 				localLen++;
	 			}
	 		}
	 		//Are diferent and ends with first char
	 		if(num[0]!=num[1] && numPos){
	 			localLen--;
	 		}
	 		bestLen=max(bestLen, localLen);
	 	}while(nextStr(num));
	 	cout << str.size()-bestLen << "\n";
    }
    return 0;
}
