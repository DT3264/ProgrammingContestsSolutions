
// Problem : D. Another Problem About Dividing Numbers
// Contest : Codeforces - Codeforces Round #725 (Div. 3)
// URL : https://codeforces.com/contest/1538/problem/D
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
v<int> primes;
void criba(){
	int N=1e9;
	int sN=sqrt(N)*2;
	v<bool> isPrime(sN+1, true);
	for(int i=2; i<=sN; i+=(i==2 ? 1 : 2)){
		if(isPrime[i]){
			primes.push_back(i);
			for(int j=i*2; j<+sN; j+=i){
				isPrime[j]=0;
			}
		}
	}
}
int countFactors(int x){
	int fC=0;
	for(auto &p : primes){
		while(x%p==0){
			x/=p;
			fC++;
		}
	}
	//Todavía se puede dividir uan vez más
	if(x>1) fC++;
	return fC;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    criba();
    int cases;
    cin >> cases;
    while(cases--){
    	int a, b, k;
    	cin >> a >> b >> k;
    	if(k==1){
    		//a & b son distintos
    		//Y uno divide al otro
    		if(a!=b && (a%b==0 || b%a==0)){
    			cout << "YES\n";
    			continue;
    		}
    		else{
    			cout << "NO\n";
    			continue;
    		}
    	}
    	int totalFactors=countFactors(a) + countFactors(b);
    	cout << (totalFactors>=k ? "YES" : "NO") << "\n";
    }
    return 0;
}
