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
struct SegmentTree {
    int n;
    int DONE=+1e9;
	int NOPE=-1e9;
	int UPDATE=1;
    vi A, st, lazy;
    SegmentTree(){}
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

    void update(int from, int to){ update(from, to, 1, 0, n-1); }
    void update(int from, int to, int p, int L, int R){
        propagate(p, L, R);
        if(from>R || to<L) return;
        if(L==R) st[p]=1;
        else{
            if(L>=from && R<=to){
                expandLazy(p, UPDATE);
				lazy[p]=UPDATE;
                propagate(p, L, R);
                return;
            }
            int mid=(L+R)/2;
            update(from, to, left(p), L, mid);
            update(from, to, right(p), mid+1, R);
            st[p]=getTogether(p);
        }
    }

    void propagate(int p, int L, int R){
        if(lazy[p]==DONE) return;
        applyVal(p, (R-L+1));
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
SegmentTree st;
int strPos;
string str;
void follow(int actPos, int size){
    char actChar=str[strPos++];
    if(actChar=='p'){
        size/=4;
        follow(actPos, size);
        follow(actPos+(size*1), size);
        follow(actPos+(size*2), size);
        follow(actPos+(size*3), size);
    }
    else if(actChar=='f'){
        st.update(actPos, actPos+size-1);
    }
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int cases;
    cin >> cases;
    while(cases--){
        st=SegmentTree(vi(1024, 0));
        cin >> str;
        strPos=0;
        follow(0, 1024);
        cin >> str;
        strPos=0;
        follow(0, 1024);
        cout << "There are " << st.query(0, 1024) << " black pixels." << "\n";
    }
    return 0;

}
