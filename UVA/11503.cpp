#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define sortVec sort(vec.begin(), vec.end());
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
class UnionFind{
public:
    vector<int> p, rank, sum;
    UnionFind(int n){
        rank.assign(n, 0);
        p.assign(n, 0);
        sum.assign(n, 0);
        for(int i=0; i<n; i++) p[i]=i, sum[i]=1;
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
                if(rank[x]==rank[y]) rank[y]++;
                sum[y]+=sum[x];
                sum[x]=0;
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
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int n, m;
    cin >> n;
    while(n--){
        cin >> m;
        UnionFind uf(100001);
        int actId=1;
        map<string, int> ids;
        map<int, int> groupSize;
        string p1, p2;
        for(int i=0; i<m; i++){
            cin >> p1 >> p2;
            if(ids[p1]==0){
                ids[p1]=actId++;
            }
            if(ids[p2]==0){
                ids[p2]=actId++;
            }
            int id1=ids[p1];
            int id2=ids[p2];
            if(id1!=id2) uf.unionSet(id1, id2);
            int idU=uf.findSet(id1);
            cout << uf.sum[idU] << "\n";
        }
    }
    return 0;
}
