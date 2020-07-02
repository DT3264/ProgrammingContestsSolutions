#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define si set<int>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
struct UnionFind{
    vector<int> p, rank, sum;
    UnionFind(int n){
        rank.assign(n, 0);
        p.assign(n, 0);
        sum.assign(n, 0);
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
                sum[x]+=sum[y];
                sum[y]=0;
            }
            else{
                p[x]=y;
                sum[y]+=sum[x];
                sum[x]=0;
				if(rank[x]==rank[y]) rank[y]++;
            }
        }
    }
    int numDisjoinSets(){
        int num=0;
        for(int i=0; i<p.size(); i++){
            if(p[i]==i) num++;
        }
        return num;
    }
    int sizeOfSet(int i){
        int x=findSet(i);
        return rank[x];
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
        int n, m;
        cin >> n >> m;
        UnionFind uf(n);
        for(int &x : uf.sum){
            cin >> x;
        }
        int u, v;
        for(int i=0; i<m; i++){
            cin >> u >> v;
            uf.unionSet(u, v);
        }
        bool can=true;
        for(int &x : uf.sum) if(x!=0) can=false;
        cout << (can ? "POSSIBLE" : "IMPOSSIBLE") << "\n";
    }
    return 0;

}
