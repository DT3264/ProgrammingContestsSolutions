#include<bits/stdc++.h>
#define f first
//#define s second
#define ll long long
#define vi vector<ll>
#define pii pair<ll, ll>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
struct UnionFind{
    vector<int> p, rank, sum;
    UnionFind(int n){
        rank.assign(n, 0);
        p.assign(n, 0);
        sum.assign(n, 1);
        for(int i=0; i<n; i++) p[i]=i;
    }
    int findSet(int i){
        return p[i]==i ? i : (p[i]=findSet(p[i]));
    }
    bool isSameSet(int i, int j){
        return findSet(i)==findSet(j);
    }
    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x=findSet(i);
            int y=findSet(j);
            if(rank[x]>rank[y]){
                sum[x]+=sum[y];
                p[y]=x;
            }
            else{
                p[x]=y;
                sum[y]+=sum[x];
				if(rank[x]==rank[y]) rank[y]++;
            }
        }
    }
};
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases;
    cin >> cases;
    while(cases--){
        int n, m, u, v;
        cin >> n >> m;
        UnionFind uf(n+1);
        int ans=1;
        for(int i=0; i<m; i++){
            cin >> u >> v;
            uf.unionSet(u, v);
            ans=max(ans, uf.sum[uf.findSet(u)]);
        }
        cout << ans << "\n";
    }
    return 0;

}
