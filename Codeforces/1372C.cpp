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
bool isSorted(vector<int> &vec){
    for(int i=0; i<vec.size(); i++){
        if(vec[i]!=i+1) return false;
    }
    return true;
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases, n;
    cin >> cases;
    while(cases--){
        cin >> n;
        vector<int> vec(n);
        for(int &x : vec) cin >> x;
        int startPoint=0;
        int endPoint=n-1;
        while(vec[startPoint]==startPoint+1) startPoint++;
        while(vec[endPoint]==endPoint+1) endPoint--;
        int inPlace=0;
        for(int i=startPoint; i<=endPoint; i++){
            if(vec[i]==i+1){
                inPlace++;
            }
        }
        if(isSorted(vec)) inPlace=n;
        int ans;
        if(inPlace==n) ans=0;
        else if(inPlace>0) ans=2;
        else if(inPlace==0) ans=1;
        cout << ans << "\n";
    }
    return 0;
}
