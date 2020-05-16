#include<bits/stdc++.h>
#define f first
#define s second
#define vi vector<ll>
#define ll long long
#define pii pair<ll, ll>
using namespace std;
struct Segment{
    int l, r;
    bool operator()(const Segment &p1, const Segment &p2){
        ///True si va más al final
        ///False si va más a principio
        if(p1.r-p1.l<p2.r-p2.l){
            ///P1 es menor
            return true;
        }
        else if(p1.r-p1.l==p2.r-p2.l){
            ///Si p1 va despiés de p2
            return p1.l>p2.l;
        }
        else{
            ///P1 es mayor
            return false;
        }
    }
};

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        priority_queue<Segment, vector<Segment>, Segment> pQ;
        vector<int> vec(n+1);
        pQ.push({1, n});
        Segment actPos;
        int actVal=1;
        while(!pQ.empty()){
            actPos=pQ.top();
            pQ.pop();
            int len=actPos.r-actPos.l+1;
            int pos=(actPos.l+actPos.r-(len%2==0 ? 1 : 0))/2;
            vec[pos]=actVal++;
            if(pos-1>=1 && pos-1>=actPos.l){
                pQ.push({actPos.l, pos-1});
            }
            if(pos+1<=n && pos+1<=actPos.r){
                pQ.push({pos+1, actPos.r});
            }
        }
        for(int i=1; i<=n; i++){
            cout << vec[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
