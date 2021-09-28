#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
using namespace std;
template<class T>
using v=vector<T>;
// Kudos to red-green-code
// https://www.redgreencode.com/equation-solving-is-the-key-to-uva-11236/
string getNum(ll x){
	string num=to_string(x);
	string str="";
	if(num.size()==1){
		str+="0.0";
		str+=num[0];
	}
	else if(num.size()==2){
		str+="0.";
		str+=num[0];
		str+=num[1];
	}
	else if(num.size()==3){
		str+=num[0];
		str+=".";
		str+=num[1];
		str+=num[2];
	}
	else if(num.size()==4){
		str+=num[0];
		str+=num[1];
		str+=".";
		str+=num[2];
		str+=num[3];
	}
	return str;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int a;
    cin >> a;
    ll limit=2000;
    ll prodLimit=2000000000;
    // Límites manuales
    ll lA=125, lB=592, lC=884;
    for(ll i=1; i<=lA; i++){
    	for(ll j=i; j<=lB; j++){
	    	for(ll k=j; k<=lC; k++){
    			ll a=i+j+k;
    			ll b=i*j*k;
            	ll c=1000000;
            	if(b==c) continue;
            	ll d=c*a;
            	ll e=b-c;
            	if(d%e!=0) continue;
            	ll l=d/e;
            	if(k>l || a+l>limit || b*l>prodLimit) continue;
				cout << getNum(i) << ' ' << getNum(j) << ' ' << getNum(k) << ' ' << getNum(l) << '\n';
			}
    	}
    }
    return 0;
}
