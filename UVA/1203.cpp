#include<bits/stdc++.h>
#define f first
#define s second
#define vi vector<ll>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sortVec sort(vec.begin(), vec.end());
#define debug if(printDebug)
bool printDebug=false;
using namespace std;
struct P{
    int id, val;
    bool operator()(const P &p1, const P &p2){
        if(p1.val<p2.val){
            return false;
        }
        if(p1.val==p2.val){
            return p1.id>p2.id;
        }
        return true;
    }
};
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    priority_queue<P, vector<P>, P> pq;
    string str;
    int id, period;
    while(cin >> str){
        if(str=="#"){
            break;
        }
        else cin >> id >> period;
        for(int i=1; i<=10000; i++){
            pq.push({id, period*i});
        }
    }
    int k;
    cin >> k;
    for(int i=0; i<k; i++){
        cout << pq.top().id << "\n";
        pq.pop();
    }
    return 0;
}
