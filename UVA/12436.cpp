#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<ll>
#define pii pair<ll, ll>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
struct Op{
    ll op;
    ll val;
};
struct SegmentTree {
    ll n=250002;
    ll DONE=0;
	ll NOPE=-1e9;
	ll A=1;
	ll B=2;
	ll C=3;
    vi st;
    vector<queue<Op>> lazy;
    SegmentTree():  st(4 * n, 0){
        queue<Op> q;
        lazy=vector<queue<Op>>(4*n, q);
    }
    ll left(ll p) {
        return p << 1;
    }
    ll right(ll p) {
        return (p << 1)+1;
    }
    ll conquer(ll a, ll b) {
        if(a==NOPE) return b;
        if(b==NOPE) return a;
        return a+b;
    }
    void expandLazy(ll p, Op val){
        if(val.op==C){
            while(lazy[left(p)].size()>0) lazy[left(p)].pop();
            while(lazy[right(p)].size()>0) lazy[right(p)].pop();
        }
        lazy[left(p)].push(val);
        lazy[right(p)].push(val);
    }
    void applyVal(ll p, ll val){
        st[p]=val;
    }
    ll getTogether(ll p){
        return conquer(st[left(p)], st[right(p)]);
    }
    ll sum(ll n){
        return (n*(n+1))/2;
    }
    ll getA(ll L, ll R, ll start){
        ll iS=sum(R)-sum(L-1);
        ll stS=start*(R-L+1);
        ll oneS=R-L+1;
        return iS-stS+oneS;
    }
    ll getB(ll L, ll R, ll end){
        ll ndS=end*(R-L+1);
        ll iS=sum(R)-sum(L-1);
        ll oneS=R-L+1;
        return ndS-iS+oneS;
    }
    ll getC(ll L, ll R, ll val){
        return val*(R-L+1);
    }
    void updateA(ll from, ll to) { updateA(from, to, 1, 0, n-1); }
    void updateA(ll from, ll to, ll p, ll L, ll R) {
        propagate(p, L, R);
        if(from>R || to<L) return;
        if(L==R){
            lazy[p].push({A, from});
            propagate(p, L, R);
        }
        else{
            if(L>=from && R<=to){
                lazy[p].push({A, from});
                propagate(p, L, R);
                return;
            }
            ll mid=(L+R)/2;
            updateA(from, to, left(p), L, mid);
            updateA(from, to, right(p), mid+1, R);
            st[p]=getTogether(p);
        }
    }

    void updateB(ll from, ll to) { updateB(from, to, 1, 0, n-1); }
    void updateB(ll from, ll to, ll p, ll L, ll R) {
        propagate(p, L, R);
        if(from>R || to<L) return;
        if(L==R){
            lazy[p].push({B, to});
            propagate(p, L, R);
        }
        else{
            if(L>=from && R<=to){
                lazy[p].push({B, to});
                propagate(p, L, R);
                return;
            }
            ll mid=(L+R)/2;
            updateB(from, to, left(p), L, mid);
            updateB(from, to, right(p), mid+1, R);
            st[p]=getTogether(p);
        }
    }

    void updateC(ll from, ll to, ll val) { updateC(from, to, 1, 0, n-1, val); }
    void updateC(ll from, ll to, ll p, ll L, ll R, ll val) {
        propagate(p, L, R);
        if(from>R || to<L) return;
        if(L==R){
            lazy[p].push({C, val});
            propagate(p, L, R);
        }
        else{
            propagate(p, L, R);
            if(L>=from && R<=to){
                while(lazy[p].size()>0) lazy[p].pop();
                lazy[p].push({C, val});
                propagate(p, L, R);
                return;
            }
            ll mid=(L+R)/2;
            updateC(from, to, left(p), L, mid, val);
            updateC(from, to, right(p), mid+1, R, val);
            st[p]=getTogether(p);
        }
    }

    void propagate(ll p, ll L, ll R){
        if(lazy[p].empty()) return;
        while(!lazy[p].empty()){
            ll val;
            if(lazy[p].front().op==A){
                val=st[p]+getA(L, R, lazy[p].front().val);
            }
            else if(lazy[p].front().op==B){
                val=st[p]+getB(L, R, lazy[p].front().val);
            }
            else if(lazy[p].front().op==C){
                val=getC(L, R, lazy[p].front().val);
            }
            applyVal(p, val);
            if(L!=R){
                expandLazy(p, lazy[p].front());
            }
            lazy[p].pop();
        }
    }

    ll query(ll from, ll to) { return query(from, to, 1, 0, n-1); }
    ll query(ll from, ll to, ll p, ll L, ll R) {
        if(from>R || to<L) return NOPE;
        propagate(p, L, R);
        if(L>=from && R<=to) return st[p];
        ll mid=(L+R)/2;
        ll q1=query(from, to, left(p), L, mid);
        ll q2=query(from, to, right(p), mid+1, R);
        return conquer(q1, q2);
    }
};
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    SegmentTree st;
    char op;
    ll L, R, val, q;
    cin >> q;
    while(q--){
        cin >> op >> L >> R;
        if(op=='A') st.updateA(L, R);
        else if(op=='B') st.updateB(L, R);
        else if(op=='C'){
            cin >> val;
            st.updateC(L, R, val);
        }
        else if(op=='S') cout << st.query(L, R) << "\n";
    }
    return 0;

}
