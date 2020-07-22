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
    	string str1, str2;
    	cin >> n >> str1 >> str2;
    	vector<int> ans1, ans2;
    	for(int i=1; i<n; i++){
    		if(str1[i]!=str1[i-1]) ans1.push_back(i);
    	}
    	if(str1[n-1]=='1') ans1.push_back(n);
    	for(int i=1; i<n; i++){
    		if(str2[i]!=str2[i-1]) ans2.push_back(i);
    	}
    	if(str2[n-1]=='1') ans2.push_back(n);
    	cout << ans1.size()+ans2.size();
    	for(int i=0; i<ans1.size(); i++) cout << " " << ans1[i];
    	for(int i=ans2.size()-1; i>=0; i--) cout << " " << ans2[i];
    	cout << "\n";
    }
    return 0;
}
