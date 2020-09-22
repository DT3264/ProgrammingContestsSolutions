
// Problem : A. Digit Game
// Contest : Codeforces - Codeforces Round #671 (Div. 2)
// URL : https://codeforces.com/contest/1419/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	int n;
    	string num;
    	cin >> n >> num;
    	int odd1=0, odd2=0;
    	int even1=0, even2=0;
    	for(int i=0; i<num.size(); i+=2){
    		int n1=num[i]-'0';
    		int n2=-1;
    		if(i+1<num.size()) n2=num[i+1]-'0';
    		if(n1%2!=0) odd1++;
    		else even1++;
    		if(n2>=0){
    			if(n2%2==0) even2++;
    			else odd2++;
    		} 
    	}
    	while(odd1+even1+odd2+even2>1){
    		if(even1>0) even1--;
    		else odd1--;
    		if(odd1+even1+odd2+even2>1){
	    		if(odd2>0) odd2--;
	    		else even2--;
    		}
    	}
    	int winner;
    	if(odd1+odd2>0) winner=1;
    	if(even1+even2>0) winner=2;
    	cout << winner << "\n";
    	
    }
    return 0;
}
