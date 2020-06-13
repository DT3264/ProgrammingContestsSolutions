#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
struct SegmentTree {
    int n;
    int DONE=0;
    int SET=1;
    int CLEAR=2;
    int FLIP=3;
    vi A, st, lazy;
    SegmentTree(const vi & a):  n(a.size()), st(4 * n), lazy(4 * n, DONE){
        A = a;
        build(1, 0, n-1);
    }

    void build(int p, int L, int R) {
        if (L == R) st[p] = A[L];
        else{
            int mid=(L+R)/2;
            build(left(p), L, mid);
            build(right(p), mid+1, R);
            st[p] = conquer(st[left(p)], st[right(p)]);
        }
    }

    int left(int p) {
        return p << 1;
    }
    int right(int p) {
        return (p << 1)+1;
    }

    int conquer(int a, int b) {
        if(a<0) return b;
        if(b<0) return a;
        return a+b;
    }

    int getFlip(int val){
        if(val==SET) return CLEAR;
        else if(val==CLEAR) return SET;
        else if(val==FLIP) return DONE;
        else if(val==DONE) return FLIP;
    }

    void expandLazy(int p, int val){
        if(val==FLIP){
            lazy[left(p)]=getFlip(lazy[left(p)]);
            lazy[right(p)]=getFlip(lazy[right(p)]);
        }
        else{
            lazy[left(p)]=lazy[right(p)]=val;
        }
    }

    void applyVal(int p, int val){
        st[p]=val;
    }

    int getTogether(int p){
        return conquer(st[left(p)], st[right(p)]);
    }

    void ones(int from, int to) { ones(from, to, 1, 0, n-1); }
    void ones(int from, int to, int p, int L, int R) {
        propagate(p, L, R);
        if(from>R || to<L) return;
        if(L==R) st[p]=1;
        else{
            if(L>=from && R<=to){
                applyVal(p, R-L+1);
                expandLazy(p, SET);
                return;
            }
            int mid=(L+R)/2;
            ones(from, to, left(p), L, mid);
            ones(from, to, right(p), mid+1, R);
            st[p]=getTogether(p);
        }
    }

    void zeros(int from, int to) { zeros(from, to, 1, 0, n-1); }
    void zeros(int from, int to, int p, int L, int R) {
        propagate(p, L, R);
        if(from>R || to<L) return;
        if(L==R) st[p]=0;
        else{
            if(L>=from && R<=to){
                applyVal(p, 0);
                expandLazy(p, CLEAR);
                return;
            }
            int mid=(L+R)/2;
            zeros(from, to, left(p), L, mid);
            zeros(from, to, right(p), mid+1, R);
            st[p]=getTogether(p);
        }
    }

    void flip(int from, int to) { flip(from, to, 1, 0, n-1); }
    void flip(int from, int to, int p, int L, int R) {
        propagate(p, L, R);
        if(from>R || to<L) return;
        if(L==R) st[p]=!st[p];
        else{
            if(L>=from && R<=to){
                applyVal(p, (R-L+1)-st[p]);
                expandLazy(p, FLIP);
                return;
            }
            int mid=(L+R)/2;
            flip(from, to, left(p), L, mid);
            flip(from, to, right(p), mid+1, R);
            st[p]=getTogether(p);
        }
    }

    void propagate(int p, int L, int R){
        if(lazy[p]==DONE) return;
        if(lazy[p]==SET){
            applyVal(p, (R-L+1));
        }
        else if(lazy[p]==CLEAR){
            applyVal(p, 0);
        }
        else if(lazy[p]==FLIP){
            applyVal(p, (R-L+1)-st[p]);
        }
        if(L!=R) expandLazy(p, lazy[p]);
        lazy[p]=DONE;
    }

    int query(int from, int to) { return query(from, to, 1, 0, n-1); }
    int query(int from, int to, int p, int L, int R) {
        if(from>R || to<L) return -1;
        propagate(p, L, R);
        if(L>=from && R<=to) return st[p];
        int mid=(L+R)/2;
        int q1=query(from, to, left(p), L, mid);
        int q2=query(from, to, right(p), mid+1, R);
        return conquer(q1, q2);
    }
};
int main(){
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases, actCase=1;
    cin >> cases;
    while(cases--){
        cout << "Case " << actCase++ << ":\n";
        int n, m;
        string str;
        cin >> n;
        vector<int> vec;
        for(int i=0; i<n; i++){
            cin >> m >> str;
            for(int j=0; j<m; j++){
                for(char c : str){
                    vec.push_back(c-'0');
                }
            }
        }
        SegmentTree st(vec);
        char op;
        int q, l, r, actOut=1;
        cin >> q;
        for(int i=0; i<q; i++){
            cin >> op >> l >> r;
            if(op=='F'){
                st.ones(l, r);
            }
            else if(op=='E'){
                st.zeros(l, r);
            }
            else if(op=='I'){
                st.flip(l, r);
            }
            else if(op=='S'){
                cout << "Q" << actOut++ << ": " << st.query(l, r) << "\n";
            }
        }
    }
	return 0;

}
