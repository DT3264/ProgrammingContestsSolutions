
// Problem : D. Number into Sequence
// Contest : Codeforces - Codeforces Round #686 (Div. 3)
// URL : https://codeforces.com/contest/1454/problem/D
// Memory Limit : 256 MB
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
typedef  unsigned long long  ull;
typedef vector<ll> vll;
const int rounds = 10;
ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}
ll mod_mul(ull a, ull b, ull mod) {
	ull ret = 0;
	for (a %= mod, b %= mod;
         b != 0;
         b >>= 1, a <<= 1, a = (a >= mod ? a - mod : a)) {
		if (b & 1) {
			ret += a;
			if (ret >= mod) {
				ret -= mod;
			}
		}
	}
	return ret;
}
ll mod_pow(ll a, ll exp, ll mod) {
	ll ans = 1;
	while (exp > 0) {
		if(exp & 1)
			ans = mod_mul(ans,a,mod);
		a = mod_mul(a,a,mod);
		exp >>= 1;
	}
	return ans;
}
bool witness(ll a, ll n) {
	ll u = n - 1;
	ll t = 0;
	if(n == a) return true;
	while (u % 2 == 0) {
		t++;
		u >>= 1;
	}
	ll next = mod_pow(a, u, n);
	if (next == 1) return false;
	ll last;
	for (int i = 0; i < t; ++i) {
		last = next;
		next = mod_mul(last, last, n);
		if (next == 1) {
            return (last != n - 1);
        }
    }
	return (next != 1);
}
///Primality test
bool miller_rabin(ull n, int it = rounds) {
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 0; i < it; ++i) {
		ll a = rand() % (n-1) + 1;
		if (witness(a, n)) {
			return false;
		}
	}
	return true;
}
///Factor generator
long long pollard_rho(ll n) {
	ll x, y, i = 1, k = 2, d;
	x = y = rand( ) % n;
	while (1) {
		++i;
		x = mod_mul(x, x, n);
		x += 2;
		if (x >= n) x -= n;
		if (x == y) return 1;
		d = gcd(abs(x - y), n);
		if (d != 1) return d;
		if (i == k) {
			y = x;
			k *= 2;
		}
	}
	return 1;
}
vll factorize(ll n) {
	vll ans;
	if (n == 1) {
		return ans;
	}
	if (miller_rabin(n)) {
		ans.push_back(n);
	} else {
		ull d = 1ull;
		while(d == 1) {
			d = pollard_rho(n);
		}
		vll dd = factorize(d);
		ans = factorize(n / d);
		for(int i = 0; i < dd.size( ); i++) {
         ans.push_back(dd[i]);
      }
	}
	return ans;
}

void addN(ll n, vll &factors, map<ll, bool> &added){
    if(!added[n]){
        factors.push_back(n);
        //added[n]=true;
    }
}

vll getFactors(ll n, vll primeFactors){
    vll factors;
    map<ll, bool> added;
    added[n]=true;
    for(ll i=0; i<primeFactors.size(); i++){
        ll actualSize=factors.size();
        for(ll j=0; j<actualSize; j++){
            ll actN=primeFactors[i]*factors[j];
            addN(actN, factors, added);
        }
        addN(primeFactors[i], factors, added);
    }
    return factors;
}

void reduce(vll &primeFacts, vll &ans){
	int aPos=0;
	for(int i=primeFacts.size()-1; i>=0; i--){
    	if(ans.size()==0 || ans[aPos]%primeFacts[i]==0){
			ans.push_back(1);
			aPos++;
		}
    	if(ans[aPos]==1 || ans[aPos]%primeFacts[i]!=0){
    		ans[aPos]*=primeFacts[i];
    	}
    }
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
    	ll n;
    	cin >> n;
	    vll primeFacts = factorize(n);
	    sort(primeFacts.begin(), primeFacts.end());
	    map<ll, ll> count;
	    v<ll> ans;
	    ll ansSize=0;
	    for(auto &x : primeFacts){
	    	count[x]++;
	    	ansSize=max(ansSize, count[x]);
	    	if(ansSize>ans.size()) ans=v<ll>(ansSize, x);
	    }
	    ll &lastN=ans[ans.size()-1];
	    ll actN=ans[0];
	    for(auto &x : primeFacts){
	    	if(x!=actN) lastN*=x;
	    }
	    cout << ans.size() << "\n";
	    for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
	    cout << "\n";
    }
    return 0;
}
