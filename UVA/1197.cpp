#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<ll>
#define pii pair<ll, ll>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
struct UnionFind{
    vector<int> p, rank, size;
    UnionFind(int n){
        rank.assign(n, 0);
        p.assign(n, 0);
        size.assign(n, 1);
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
                size[x]+=size[y];
                size[y]=0;
            }
            else{
                p[x]=y;
                size[y]+=size[x];
                size[x]=0;
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
    int n, m;
    while(cin >> n >> m && n!=0){
        int people, t1, t2;
        UnionFind uf(n+1);
        //cout << n << " people; " << m << " groups\n";
        for(int i=0; i<m; i++){
            cin >> people;
            cin >> t1;
            for(int j=1; j<people; j++){
                cin >> t2;
                uf.unionSet(t1, t2);
                t1=t2;
            }
        }
        int suspectsGroup=uf.findSet(0);
        cout << uf.size[suspectsGroup] << "\n";
    }
    return 0;

}
