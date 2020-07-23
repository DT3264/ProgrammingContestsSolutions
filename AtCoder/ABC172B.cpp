
// Problem : B - Minor Change
// Contest : AtCoder - AtCoder Beginner Contest 172
// URL : https://atcoder.jp/contests/abc172/tasks/abc172_b
// Memory Limit : 1024 MB
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
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    string s1, s2;
    cin >> s1 >> s2;
    int ans=0;
    for(int i=0; i<s1.size(); i++){
    	ans+=s1[i]!=s2[i];
    }
    cout << ans << "\n";
    return 0;
}
