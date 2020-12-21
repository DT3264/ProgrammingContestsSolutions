
// Problem : 729 - The Hamming Distance Problem
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=670
// Memory Limit : 32 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define y1 yy
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
#define noDebug if(!printDebug)
using namespace std;
template<class T>
using v=vector<T>;   
bool printDebug=false;
bool used[17];
int n;
v<string> ans;
void permu(int pos, int remain){
	if(remain==0){
		//cout << pos << "-" << remain << "\n";
		string str;
		for(int i=0; i<n; i++){
			str+=used[i]+'0';
		}
		ans.push_back(str);
		return;
	}
	if(pos==n) return;
	used[pos]=1;
	permu(pos+1, remain-1);
	used[pos]=0;
	permu(pos+1, remain);
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    int cases;
    cin >> cases;
    while(cases--){
    	int h;
    	cin >> n >> h;
    	ans.clear();
    	permu(0, h);
    	for(int i=ans.size()-1; i>=0; i--) cout << ans[i] << "\n";
    	cout << (cases>0 ? "\n" : "");
    }
    return 0;
}
