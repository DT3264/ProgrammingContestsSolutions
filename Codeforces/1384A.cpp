
// Problem : A. Common Prefixes
// Contest : Codeforces - Codeforces Round #659 (Div. 2)
// URL : https://codeforces.com/contest/1384/problem/0
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	int n;
    	cin >> n;
    	vector<int> vec(n);
    	for(int &x : vec) cin >> x;
    	string s1;
    	string s2;
    	for(int i=0; i<50; i++) s1+='a';
    	vector<string> strings={s1};
    	for(int i=0; i<n; i++){
    		s2=strings[i];
    		int pos=vec[i];
    		while(pos<50){
    			if(s2[pos]==strings[i][pos]){
    				s2[pos]++;
    				if(s2[pos]>'z') s2[pos]='a';
    				pos++;
    			}
    		}
    		strings.push_back(s2);
    	}
    	for(string &s : strings) cout << s << "\n";
    }
    return 0;
}
