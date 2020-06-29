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
    vector<int> p, rank;
    UnionFind(int n){
        rank.assign(n, 0);
        p.assign(n, 0);
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
                p[y]=x;
            }
            else{
                p[x]=y;
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
    int actCase=1;
    int n, m, u, v;
    while(cin >> n >> m){
        if(n==m && m==0) break;
        UnionFind uf(n+1);
        for(int i=0; i<m; i++){
            cin >> u >> v;
            uf.unionSet(u, v);
        }
        int ans=0;
        for(int i=1; i<=n; i++){
            if(uf.p[i]==i) ans++;
        }
        cout << "Case " << actCase++ << ": " << ans << "\n";
    }
    return 0;

}
