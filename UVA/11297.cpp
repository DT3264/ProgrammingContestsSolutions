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
struct MinSegmentTree {
    int n;
	//O el valor que convenga
    int DONE=+1e9;
	int NOPE=-1e9;
	int UPDATE=1;
    vi A, st, lazy;
    MinSegmentTree(const vi & a):  n(a.size()), st(4 * n), lazy(4 * n, DONE){
        A=a;
        build(1, 0, n-1);
    }

    void build(int p, int L, int R){
        if(L==R) st[p]=A[L];
        else{
            int mid=(L+R)/2;
            build(left(p), L, mid);
            build(right(p), mid+1, R);
            st[p]=conquer(st[left(p)], st[right(p)]);
        }
    }

    int left(int p){
        return p << 1;
    }
    int right(int p){
        return (p << 1)+1;
    }

    int conquer(int a, int b){
        if(a==NOPE) return b;
        if(b==NOPE) return a;
        return min(a,b);
    }

    void expandLazy(int p, int val){
        lazy[left(p)]=lazy[right(p)]=val;
    }

    void applyVal(int p, int val){
        st[p]=val;
    }

    int getTogether(int p){
        return conquer(st[left(p)], st[right(p)]);
    }

    void update(int from, int to, int val){ update(from, to, 1, 0, n-1, val); }
    void update(int from, int to, int p, int L, int R, int val){
        propagate(p, L, R);
        if(from>R || to<L) return;
        if(L==R) st[p]=val;
        else{
            if(L>=from && R<=to){
                expandLazy(p, val);
				lazy[p]=val;
                propagate(p, L, R);
                return;
            }
            int mid=(L+R)/2;
            update(from, to, left(p), L, mid, val);
            update(from, to, right(p), mid+1, R, val);
            st[p]=getTogether(p);
        }
    }

    void propagate(int p, int L, int R){
        if(lazy[p]==DONE) return;
        applyVal(p, st[p]*(R-L+1));
        if(L!=R) expandLazy(p, lazy[p]);
        lazy[p]=DONE;
    }

    int query(int from, int to){ return query(from, to, 1, 0, n-1); }
    int query(int from, int to, int p, int L, int R){
        if(from>R || to<L) return NOPE;
        propagate(p, L, R);
        if(L>=from && R<=to) return st[p];
        int mid=(L+R)/2;
        int q1=query(from, to, left(p), L, mid);
        int q2=query(from, to, right(p), mid+1, R);
        return conquer(q1, q2);
    }
};
struct MaxSegmentTree {
    int n;
	//O el valor que convenga
    int DONE=+1e9;
	int NOPE=-1e9;
	int UPDATE=1;
    vi A, st, lazy;
    MaxSegmentTree(vi & a):  n(a.size()), st(4 * n), lazy(4 * n, DONE){
        A=a;
        build(1, 0, n-1);
    }

    void build(int p, int L, int R){
        if(L==R) st[p]=A[L];
        else{
            int mid=(L+R)/2;
            build(left(p), L, mid);
            build(right(p), mid+1, R);
            st[p]=conquer(st[left(p)], st[right(p)]);
        }
    }

    int left(int p){
        return p << 1;
    }
    int right(int p){
        return (p << 1)+1;
    }

    int conquer(int a, int b){
        if(a==NOPE) return b;
        if(b==NOPE) return a;
        return max(a,b);
    }

    void expandLazy(int p, int val){
        lazy[left(p)]=lazy[right(p)]=val;
    }

    void applyVal(int p, int val){
        st[p]=val;
    }

    int getTogether(int p){
        return conquer(st[left(p)], st[right(p)]);
    }

    void update(int from, int to, int val){ update(from, to, 1, 0, n-1, val); }
    void update(int from, int to, int p, int L, int R, int val){
        propagate(p, L, R);
        if(from>R || to<L) return;
        if(L==R) st[p]=val;
        else{
            if(L>=from && R<=to){
                expandLazy(p, val);
				lazy[p]=val;
                propagate(p, L, R);
                return;
            }
            int mid=(L+R)/2;
            update(from, to, left(p), L, mid, val);
            update(from, to, right(p), mid+1, R, val);
            st[p]=getTogether(p);
        }
    }

    void propagate(int p, int L, int R){
        if(lazy[p]==DONE) return;
        applyVal(p, st[p]*(R-L+1));
        if(L!=R) expandLazy(p, lazy[p]);
        lazy[p]=DONE;
    }

    int query(int from, int to){ return query(from, to, 1, 0, n-1); }
    int query(int from, int to, int p, int L, int R){
        if(from>R || to<L) return NOPE;
        propagate(p, L, R);
        if(L>=from && R<=to) return st[p];
        int mid=(L+R)/2;
        int q1=query(from, to, left(p), L, mid);
        int q2=query(from, to, right(p), mid+1, R);
        return conquer(q1, q2);
    }
};
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int n;
    while(cin >> n){
        vector<vector<int>> vec(n, vector<int>(n));
        vector<MaxSegmentTree> vecStMax;
        vector<MinSegmentTree> vecStMin;
        for(auto &v : vec){
            for(int &x : v){
                cin >> x;
            }
            vecStMax.push_back(MaxSegmentTree(v));
            vecStMin.push_back(MinSegmentTree(v));
        }
        int q;
        int x1, y1, x2, y2;
        char op;
        cin >> q;
        while(q-->0){
            cin >> op;
            if(op=='q'){
                cin >> x1 >> y1 >> x2 >> y2;
                x1--; x2--; y1--; y2--;
                int ansMin=1e9;
                int ansMax=-1e9;
                for(int i=x1; i<=x2; i++){
                    ansMin=min(ansMin, vecStMin[i].query(y1, y2));
                }
                for(int i=x1; i<=x2; i++){
                    ansMax=max(ansMax, vecStMax[i].query(y1, y2));
                }
                cout << ansMax << " " << ansMin << "\n";
            }
            else if(op=='c'){
                int u, v, val;
                cin >> u >> v >> val;
                u--, v--;
                vecStMax[u].update(v, v, val);
                vecStMin[u].update(v, v, val);
            }
        }
    }
    return 0;

}
