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
        sum.assign(n, 1);
        for(int i=0; i<n; i++) p[i]=i;
    }
    int findSet(int i){
        return p[i]==i ? i : (p[i]=findSet(p[i]));
    }
    bool isSameSet(int i, int j){
        return findSet(i)==findSet(j);
    }
    int unionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x=findSet(i);
            int y=findSet(j);
            if(rank[x]>rank[y]){
                p[y]=x;
                sum[x]+=sum[y];
                return sum[x];
            }
            else{
                p[x]=y;
                sum[y]+=sum[x];
				if(rank[x]==rank[y]) rank[y]++;
				return sum[y];
            }
        }
        return 1;
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
    int n, m;
    while(cin >> n >> m){
        if(n==m && m==0) break;
        UnionFind uf(n);
        map<string, int> ids;
        string animal;
        for(int i=0; i<n; i++){
            cin >> animal;
            ids[animal]=i;
        }
        string u, v;
        int ans=1;
        for(int i=0; i<m; i++){
            cin >> u >> v;
            int uId=ids[u];
            int vId=ids[v];
            ans=max(ans, uf.unionSet(uId, vId));
        }
        cout << ans << "\n";
    }
    return 0;

}
