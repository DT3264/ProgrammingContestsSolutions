#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define sortVec sort(vec.begin(), vec.end());
#define debug if(printDebug)
bool printDebug=false;
using namespace std;
class UnionFind{
public:
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
    string waked;
    while(cin >> n){
        cin >> m;
        cin >> waked;
        UnionFind uf(27);
        uf.unionSet(waked[0]-'A', waked[1]-'A');
        uf.unionSet(waked[0]-'A', waked[2]-'A');
        int wakedSet=uf.findSet(waked[0]-'A');
        vector<vi> links(27);
        set<int> zones;
        char u, v;
        for(int i=0; i<m; i++){
            cin >> u >> v;
            zones.insert(u-'A');
            zones.insert(v-'A');
            links[u-'A'].push_back(v-'A');
            links[v-'A'].push_back(u-'A');
        }
        zones.erase(waked[0]-'A');
        zones.erase(waked[1]-'A');
        zones.erase(waked[2]-'A');
        int years=0;
        if(n>3 && zones.size()==0){
            years=-1;
        }
        while(zones.size()>0){
            vector<int> toWake;
            for(int zone : zones){
                int sum=0;
                for(int &x : links[zone]){
                    int xSet=uf.findSet(x);
                    if(xSet==wakedSet){
                        sum++;
                    }
                }
                if(sum>=3){
                    toWake.push_back(zone);
                }
            }
            if(toWake.size()>0){
                for(int &zoneToWake : toWake){
                    uf.unionSet(zoneToWake, wakedSet);
                    zones.erase(zoneToWake);
                }
                years++;
            }
            else{
                years=-1;
                break;
            }
        }
        if(years==-1){
            cout << "THIS BRAIN NEVER WAKES UP\n";
        }
        else{
            cout << "WAKE UP IN, " << years << ", YEARS\n";
        }
    }
    return 0;
}
