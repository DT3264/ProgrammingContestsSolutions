#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
bool printDebug=false;
using namespace std;
template<class T>
using v=vector<T>;
bool used[101];
int main(){
    // printDebug=true;
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    set<pii> st;
    for(int i=a; i<b; i++){
    	st.insert({i,i+1});
    }
    for(int i=c; i<d; i++){
    	st.insert({i,i+1});
    }
    cout << st.size() << '\n';
    return 0;
}
