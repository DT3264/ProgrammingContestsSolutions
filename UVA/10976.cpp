#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
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
    int n;
    while(cin >> n){
        vector<pii> vec;
        for(int i=n+1; i<=n*2; i++){
            if((i*n)%(i-n)==0){
                vec.push_back({(i*n)/(i-n), i});
            }
        }
        cout << vec.size() << "\n";
        for(auto &p : vec){
            cout << "1/" << n << " = ";
            cout << "1/" << p.f << " + ";
            cout << "1/" << p.s << "\n";
        }
    }
    return 0;

}
