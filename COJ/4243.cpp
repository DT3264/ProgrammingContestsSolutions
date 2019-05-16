#include <iostream>
#include <vector>
#include <map>

#include <algorithm> // __gcd()
#include <cstring> // memset()
#include <cassert> // assert()
using namespace std;
#define ll long long
typedef long double dbl;

const ll N=2e6+10;

ll np, prime[N];
bool isp[N];
void sieve(ll N) {
    memset(isp, true, sizeof isp);
    isp[0] = isp[1] = false;
    for(ll i=2; i<N; i++) if(isp[i]) {
        prime[++np]=i;
        for(ll j=2*i; j<N; j+=i) {
            isp[j]=false;
        }
    }
}

inline ll mul(ll a, ll b, ll m) {
	a%=m; if(a<0) a+=m;
	b%=m; if(b<0) b+=m;
	ll q = ((dbl)a * (dbl)b) / (dbl)m;
	ll r = a*b - q*m;
	return (r<0 ? r+m:r);
}
inline ll pwr(ll a, ll n, ll m) {
    ll ans(1);
    while(n) {
        if(n & 1) ans = mul(ans, a, m);
        if(n >>= 1) a = mul(a, a, m);
    }
    return ans%m;
}
ll myrand(ll n) {
	return rand()%n*rand()%n*rand()%n;
}
bool ispmiller(ll p) { // O(30*logp)
	if(p<2) return false;
	if(p==2) return true;
	if(p%2==0) return false;
	ll s=p-1; s>>=__builtin_ctzll(s);
	for(ll i=0; i<60; i++) {
		ll val=pwr(myrand(p-1)+1,s,p), temp=s;
		while(temp!=p-1 and 1<val and val<p-1) {
			val=mul(val,val,p);
			temp<<=1;
		}
		if(val!=p-1 and temp%2==0) return false;
	}
	return true;
}
inline ll pollardrho(ll n) { // O(n^0.25)
	if(n==1) return 1;
	if(n%2==0) return 2;
	ll c=myrand(n-1)+1, x=myrand(n-2)+2, y=x;
	ll d=1; while(d==1) {
		x=mul(x,x,n)+c; if(x>=n) x-=n;
		y=mul(y,y,n)+c; if(y>=n) y-=n;
		y=mul(y,y,n)+c; if(y>=n) y-=n;
		d=__gcd(abs(x-y),n);
		if(d==n) return (ispmiller(n) ? n:pollardrho(n));
	}
	return d;
}

vector<ll> primeFactors; // holds the prime factorisation of input n
vector<ll> factors; // holds the prime factorisation of input n
void getPrimeFactors(ll n){
    for(ll i=1; i<np and prime[i]*prime[i]<=n; i++) {
    	if(n%prime[i]==0) { // n is divisible by prime[i] (<= 1e6)
    		while(n%prime[i]==0) {
    			n /= prime[i];
    			primeFactors.push_back(prime[i]);
    		}
    	}
    }

    if(ispmiller(n)) {
    	primeFactors.push_back(n);
    }
    else if(n>1) { // n still has some prime factors > 1e6
    	ll x = pollardrho(n);
    	assert(x > 1e6);
    	primeFactors.push_back(x);
    	primeFactors.push_back(n/x);
    }
}
void getFactors(ll n){
    map<ll, bool> added;
    added[n]=true;
    for(ll i=0; i<primeFactors.size(); i++){
        ll actualSize=factors.size();
        for(ll j=0; j<actualSize; j++){
            if(!added[primeFactors[i]*factors[j]]){
                factors.push_back(primeFactors[i]*factors[j]);
                added[primeFactors[i]*factors[j]]=true;
            }
        }
        if(!added[primeFactors[i]]){
            factors.push_back(primeFactors[i]);
            added[primeFactors[i]]=true;
        }
    }
}

ll sumToN(ll n){
    return (n*(n+1))/2;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    sieve(1e6);
    ll t, n;
    cin >> t;
    for(ll i=0; i<t; i++){
        cin >> n;
        factors=vector<ll>();
        primeFactors=vector<ll>();
        getPrimeFactors(n);
        getFactors(n+1);
        ll cont=0;
        for(ll j=0; j<factors.size(); j++){
            if(factors[j]%2!=0){
                cont++;
            }
        }
        cout << "case " << i+1 << ": " << cont << "\n";
    }
    return 0;
}
