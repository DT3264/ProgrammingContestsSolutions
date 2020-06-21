#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<ll>
#define pii pair<ll, ll>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
struct S{
    int ind;
    string str;
};
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int n;
    string str;
    cin >> n;
    cin.ignore();
    while(n--){
        int t;
        double u;
        getline(cin, str);
        getline(cin, str);
        stringstream ss(str);
        vector<S> vec;
        while(ss >> t) vec.push_back({t, ""});
        getline(cin, str);
        ss=stringstream(str);
        for(auto &x : vec) ss >> x.str;
        sort(vec.begin(), vec.end(), [](const S &s1, const S &s2){
            return s1.ind<s2.ind;
        });
        for(auto &x : vec) cout << x.str << "\n";
        if(n>0) cout << "\n";
    }
    return 0;

}
