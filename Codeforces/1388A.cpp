// Problem : A. Captain Flint and Crew Recruitment
// Contest : Codeforces - Codeforces Round #660 (Div. 2)
// URL : https://codeforces.com/contest/1388/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi primestor<int>
#define pii pair<int, int>
#define si set<int>
#define y1 yy
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
vector<int> primes;
vector<int> nearP;
int maxN=20000;
void generatePrimes(){
	vector<bool> mark(maxN+1, false);
	for(ll i=2; i<maxN+1; i++){
		if(!mark[i]){
			primes.push_back(i);
			for(ll j=i*i; j<maxN+1; j+=i){
				mark[j]=true;
			}
		}
	}
}
void generateNearPrimes(){
	vector<bool> mark(maxN+1, false);
	for(int i=0; i<primes.size(); i++){
		for(int j=i+1; j<primes.size(); j++){
			if(primes[i]*primes[j]<=maxN && !mark[primes[i]*primes[j]]){
				mark[primes[i]*primes[j]]=true;
				nearP.push_back(primes[i]*primes[j]);
			}
		}
	}
}
int n;
bool found;
vector<int> ans={0,0,0,0};
void reach(int pos){
	if(found) return;
	if(pos==3){
		ans[3]=n-(ans[2]+ans[1]+ans[0]);
		if(ans[3]!=ans[2] && ans[3]!=ans[1] && ans[3]!=ans[0] && ans[3]>=1){
			found=true;
		}
		return;
	}
	for(int i=pos; i<5 && !found; i++){
		ans[pos]=nearP[i];
		reach(pos+1);
	}
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    generatePrimes();
    generateNearPrimes();
    sort(nearP.begin(), nearP.end());
    int cases;
    cin >> cases;
    while(cases--){
    	found=false;
    	cin >> n;
    	if(n>30){
    		cout << "YES\n";
    		reach(0);
    		for(int &x : ans) cout << x << " ";
    		cout << "\n";
    	}
    	else{
    		cout << "NO\n";
    	}
    }
    return 0;
}