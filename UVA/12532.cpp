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
    int NOPE=1e8;
    vi A, st;
    SegmentTree(const vi & a):  n(a.size()), st(4 * n){
        A=a;
        build(1, 0, n-1);
    }

    void build(int p, int L, int R) {
        if (L==R) st[p]=A[L];
        else{
            int mid=(L+R)/2;
            build(left(p), L, mid);
            build(right(p), mid+1, R);
            st[p]=conquer(st[left(p)], st[right(p)]);
        }
    }

    int left(int p) {
        return p << 1;
    }
    int right(int p) {
        return (p << 1)+1;
    }

    int conquer(int a, int b) {
        if(a==NOPE) return b;
        if(b==NOPE) return a;
        return a*b;
    }

    int getTogether(int p){
        return conquer(st[left(p)], st[right(p)]);
    }

    void update(int from, int to, int val) { update(from, to, 1, 0, n-1, val); }
    void update(int from, int to, int p, int L, int R, int val) {
        if(from>R || to<L) return;
        if(L==R){
            st[p]=val;
        }
        else{
            int mid=(L+R)/2;
            update(from, to, left(p), L, mid, val);
            update(from, to, right(p), mid+1, R, val);
            st[p]=getTogether(p);
        }
    }

    int query(int from, int to) { return query(from, to, 1, 0, n-1); }
    int query(int from, int to, int p, int L, int R) {
        if(from>R || to<L) return NOPE;
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
	int n, m;
    while(cin >> n){
        cin >> m;
        vector<int> vec(n);
        for(int &x : vec){
            cin >> x;
            if(x<0) x=-1;
            else if(x>0) x=1;
        }
        SegmentTree st(vec);
        char op;
        int v1, v2;
        string ans="";
        for(int i=0; i<m; i++){
            cin >> op >> v1 >> v2;
            if(op=='C'){
                v1--;
                if(v2<0) v2=-1;
                else if(v2>0) v2=1;
                st.update(v1, v1, v2);
            }
            else if(op=='P'){
                v1--;
                v2--;
                int v=st.query(v1, v2);
                if(v<0) ans+="-";
                else if(v==0) ans+="0";
                else if(v>0) ans+="+";
            }
        }
        cout << ans << "\n";
    }
	return 0;

}
