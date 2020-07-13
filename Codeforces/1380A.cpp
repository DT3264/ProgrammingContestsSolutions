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
    int cases, n;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        vector<int> vec(n);
        for(int &x : vec) cin >> x;
        int p1=0;
        while(p1<n && vec[p1]>=vec[p1+1] && p1+1<n) p1++;
        int p2=p1+1;
        while(p2<n && vec[p2]<=vec[p2+1] && p2+1<n) p2++;
        int p3=p2+1;
        while(p3<n && vec[p3]>=vec[p3+1] && p3+1<n) p3++;
        bool can=true;
        if(p1>=n || p2>=n || p3>=n) can=false;
        if(can && vec[p1]>=vec[p2] && vec[p2]<=vec[p3]) can=false;
        cout << (can ? "YES" : "NO") << "\n";
        if(can) cout << p1+1 << " " << p2+1 << " " << p3+1 << "\n";
    }
    return 0;
}
