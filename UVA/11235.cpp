#include<bits/stdc++.h>
#define vi vector<int>
/*#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define sortVec sort(vec.begin(), vec.end());*/
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
class SegmentTree {                              // OOP style
private:
  int n;                                         // n = (int)A.size()
  vi A, st, lazy;                                // the arrays

  int l(int p) { return  p<<1; }                 // go to left child
  int r(int p) { return (p<<1)+1; }              // go to right child

  ///Return the op bewteen the vals,
  ///minN, maxN, addition or substraction
  int conquer(int a, int b){
    if(a==-1) return b;
    if(b==-1) return a;
    return max(a, b);
  }

  void build(int p, int L, int R) {              // O(n)
    if (L == R)
      st[p] = A[L];                              // base case
    else {
      int m = (L+R)/2;
      build(l(p), L  , m);
      build(r(p), m+1, R);
      st[p]=conquer(st[l(p)], st[r(p)]);
    }
  }

  void propagate(int p, int L, int R) {
    if (lazy[p] != -1) {                         // has a lazy flag
      st[p] = lazy[p];                           // [L..R] has same value
      if (L != R)                                // not a leaf
        lazy[l(p)] = lazy[r(p)] = lazy[p];       // propagate downwards
      else                                       // L == R, a single index
        A[L] = lazy[p];                          // time to update this
      lazy[p] = -1;                              // erase lazy flag
    }
  }

  int RMQ(int p, int L, int R, int i, int j) {   // O(log n)
    propagate(p, L, R);                          // lazy propagation
    if (i > j) return -1;                        // infeasible
    if ((L >= i) && (R <= j)) return st[p];      // found the segment
    int m = (L+R)/2;
    int lTree=RMQ(l(p), L  , m, i          , min(m, j));
    int rTree=RMQ(r(p), m+1, R, max(i, m+1), j        );
    return conquer(lTree, rTree);
  }

  void update(int p, int L, int R, int i, int j, int val) { // O(log n)
    propagate(p, L, R);                          // lazy propagation
    if (i > j) return;
    if ((L >= i) && (R <= j)) {                  // found the segment
      lazy[p] = val;                             // update this
      propagate(p, L, R);                        // lazy propagation
    }
    else {
      int m = (L+R)/2;
      update(l(p), L  , m, i          , min(m, j), val);
      update(r(p), m+1, R, max(i, m+1), j        , val);
      int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
      int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
      st[p]=conquer(lsubtree, rsubtree);
    }
  }

public:
  SegmentTree(int sz) : n(sz), st(4*n), lazy(4*n, -1) {}
  SegmentTree(const vi &_A) : SegmentTree((int)_A.size()) {
    A = _A;
    build(1, 0, n-1);
  }
  void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }
  int RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }
};

struct Segment{
    int start;
    int end;
};
void expand(vector<int> &vecFreq, vector<Segment> &segments, int start, int end){
    int sum=end-start+1;
    for(int i=start; i<=end; i++){
        vecFreq[i]=sum;
        segments[i].start=start;
        segments[i].end=end;
    }
}
int main(){
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);//*/
    int n, m;
    while(cin >> n){
        if(n==0) break;
        cin >> m;
        vector<int> vec(n), vecFreq(n);
        vector<Segment> segments(n);
        for(int &x : vec){
            cin >> x;
        }
        int start=0;
        for(int i=1; i<vec.size(); i++){
            if(vec[i]!=vec[i-1]){
                expand(vecFreq, segments, start, i-1);
                start=i;
            }
        }
        expand(vecFreq, segments, start, n-1);

        SegmentTree st(vecFreq);
        int l, r, ans;
        while(m--){
            cin >> l >> r;
            l--;
            r--;
            if(vec[l]!=vec[r]){
                int v1L=l;
                int v1R=segments[l].end;
                int v1A=v1R-v1L+1;

                int v2R=r;
                int v2L=segments[r].start;
                int v2A=v2R-v2L+1;

                int v3A=st.RMQ(v1R+1, v2L-1);

                ans=max(v1A, v2A);
                ans=max(ans, v3A);
            }
            else{
                ans=r-l+1;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
