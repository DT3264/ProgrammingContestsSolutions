#include<bits/stdc++.h>
#define f first
#define s second
#define vi vector<ll>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sortVec sort(vec.begin(), vec.end());
#define debug if(printDebug)
bool printDebug=false;
using namespace std;
struct P{
    int val;
    bool operator()(const P &p1, const P &p2){
        if(p1.val<p2.val){
            return false;
        }
        else return true;
    }
};
int main(){
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int n, t;
    while(cin >> n){
        priority_queue<P, vector<P>, P> pq;
        if(n==0) break;
        for(int i=0; i<n; i++){
            cin >> t;
            pq.push({t});
        }
        int ans=0;
        while(pq.size()>1){
            int v1=pq.top().val;
            pq.pop();
            int v2=pq.top().val;
            pq.pop();
            int cost=v1+v2;
            ans+=cost;
            pq.push({cost});
        }
        cout << ans << "\n";
    }
    return 0;
}
