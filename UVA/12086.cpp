#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define si set<int>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
struct SegmentTree {
    int n;
	//O el valor que convenga
    int DONE=+1e9;
	int NOPE=-1e9;
	int UPDATE=1;
    vi A, st, lazy;
    SegmentTree(const vi & a):  n(a.size()), st(4 * n), lazy(4 * n, DONE){
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
        return a+b;
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
    int actCase=1;
    while(cin >> n){
        if(n==0) break;
        if(actCase>1) cout << "\n";
        cout << "Case " << actCase++ << ":\n";
        vector<int> vec(n);
        for(int &x : vec) cin >> x;
        SegmentTree st(vec);
        cin.ignore();
        string str;
        char op;
        int u, v;
        while(getline(cin, str)){
            if(str=="END") break;
            stringstream ss(str);
            ss >> op >> u >> v;
            u--;
            if(op=='M') v--;
            //cout << op << ": " << u << ", " << v << "\n";
            if(op=='M') cout << st.query(u, v) << "\n";
            else if(op=='S') st.update(u, u, v);
        }
    }
    return 0;

}
