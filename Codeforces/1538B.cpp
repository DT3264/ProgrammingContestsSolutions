
// Problem : B. Friends and Candies
// Contest : Codeforces - Codeforces Round #725 (Div. 3)
// URL : https://codeforces.com/contest/1538/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
using namespace std;
template<class T>
using v=vector<T>;
int main(){
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int cases;
    cin >> cases;
    while(cases--){
    	int n;
    	cin >> n;
    	v<int> vec(n), sum(n);
    	for(int &x : vec) cin >> x;
    	sort(vec.begin(), vec.end());
    	sum[0]=vec[0];
    	int iguales=1;
    	for(int i=1; i<n; i++){
    		sum[i]=vec[i]+sum[i-1];
    		if(vec[i]==vec[0]) iguales++;
    	}
    	int sumT=sum[n-1];
    	int best=-1;
    	int l=0, r=n-1;
    	if(iguales==n){
    		//Ya son iguales
    		cout << "0\n";
    		continue;
    	}
    	if(sumT%n!=0){
    		//No se podrá logra
    		cout << "-1\n";
    		continue;
    	}
    	int ans=-1;
    	int val=sumT/n;
    	for(int i=0; i<n && ans==-1; i++){
    		if(vec[i]>val) ans=i;
    	}
    	cout << n-ans << "\n";
    }
    return 0;
}
