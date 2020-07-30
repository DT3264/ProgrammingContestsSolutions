     
    // Problem : A. LCM Problem
    // Contest : Codeforces - Educational Codeforces Round 92 (Rated for Div. 2)
    // URL : https://codeforces.com/contest/1389/problem/0
    // Memory Limit : 256 MB
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
    ll gcd(ll a, ll b){
        if(a==0) return b;
        return gcd(b%a, a);
    }
    ll lcm(ll a, ll b){
        return (a*b)/gcd(a, b);
    }
    int main(){
        //printDebug=true;
        /*freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);//*/
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);//*/
        int cases;
        cin >> cases;
        while(cases--){
        	int l, r;
        	cin >> l >> r;
        	int ans=-1;
        	for(int i=l; i<=r; i++){
        		if(i*2<=r){
        			ans=i;
        			break;
        		}
        	}
        	cout << ans << " " << (ans>0 ? ans*2 : ans) << "\n";
        }
        return 0;
    }