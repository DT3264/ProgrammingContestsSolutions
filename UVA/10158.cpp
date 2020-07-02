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
    vector<int> p, rank;
    vector<si> enemies;
    UnionFind(int n){
        rank.assign(n, 0);
        p.assign(n, 0);
        enemies.assign(n, si());
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
                for(int e : enemies[y]) enemies[x].insert(e);
            }
            else{
                p[x]=y;
                for(int e : enemies[x]) enemies[y].insert(e);
				if(rank[x]==rank[y]) rank[y]++;
            }
        }
    }

    bool setFriends(int i, int j){
        int x=findSet(i);
        int y=findSet(j);
        if(areEnemies(i, j)) return false;
        if(areFriends(i, j)) return true;
        unionSet(x, y);
        for(int e1 : enemies[x]){
            for(int e2 : enemies[y]){
                unionSet(e1, e2);
            }
        }
        return true;
    }
    bool setEnemies(int i, int j){
        int x=findSet(i);
        int y=findSet(j);
        if(areFriends(i, j)) return false;
        if(areEnemies(i, j)) return true;
        for(int e : enemies[y]){
            unionSet(e, x);
        }
        for(int e : enemies[x]){
            unionSet(e, y);
        }
        enemies[x].insert(y);
        enemies[y].insert(x);
        return true;
    }
    bool areFriends(int i, int j){
        int x=findSet(i);
        int y=findSet(j);
        return x==y;
    }
    bool areEnemies(int i, int j){
        int x=findSet(i);
        int y=findSet(j);
        ///Ambos son enemigos
        return enemies[x].count(y) && enemies[y].count(x);
    }
};
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int n;
    int op, u, v;
    cin >> n;
    UnionFind uf(n);
    while(cin >> op >> u >> v){
        if(op==0 && u==0 && v==0) break;
        if(op==1) cout << (uf.setFriends(u, v) ? "" : "-1\n");
        else if(op==2) cout << (uf.setEnemies(u, v) ? "" : "-1\n");
        else if(op==3) cout << uf.areFriends(u, v) << "\n";
        else if(op==4) cout << uf.areEnemies(u, v) << "\n";
    }
    return 0;

}
