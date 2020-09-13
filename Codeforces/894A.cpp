
// Problem : A. QAQ
// Contest : Codeforces - Codeforces Round #447 (Div. 2)
// URL : https://codeforces.com/problemset/problem/894/A
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
    string str;
    cin >> str;
    int ans=0;
    int qs=0;
    for(int i=0; i<str.size(); i++){
    	if(str[i]=='Q'){
    		qs++;
    	}
    }
    int left=0, right=qs;
    for(int i=0; i<str.size(); i++){
    	if(str[i]=='Q'){
    		left++;
    		right--;
    	}
    	if(str[i]=='A'){
    		ans+=(left*right);
    	}
    }
    cout << ans << "\n";
    return 0;
}
