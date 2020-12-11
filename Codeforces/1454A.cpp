
// Problem : A. Special Permutation
// Contest : Codeforces - Codeforces Round #686 (Div. 3)
// URL : https://codeforces.com/contest/1454/problem/A
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
#define noDebug if(!printDebug)
using namespace std;
template<class T>
using v=vector<T>;   
bool printDebug=false;
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    noDebug ios_base::sync_with_stdio(0);
    noDebug cin.tie(0);
    int cases;
    cin >> cases;
    while(cases--){
    	int t;
    	cin >> t;
    	vi vec;
    	for(int i=t; i>0; i--){ 
    		vec.push_back(i);
    		if(vec.size()==i){
    			swap(vec[vec.size()-1], vec[vec.size()-2]);
    		}
    	}
    	for(int &x : vec) cout << x << " ";
    	cout << "\n";
    }
    return 0;
}
