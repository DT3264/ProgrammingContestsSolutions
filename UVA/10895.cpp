#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define sortVec sort(vec.begin(), vec.end());
#define debug if(printDebug)
bool printDebug=false;
using namespace std;
struct P{
    int row, col, val;
};
int main(){
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int n, m;
    int nums, row, val;
    while(cin >> n >> m){
        vector<P> vec;
        for(int row=0; row<n; row++){
            cin >> nums;
            vector<int> index(nums);
            for(int &x : index){
                cin >> x;
            }
            for(int &col : index){
                cin >> val;
                vec.push_back({row, col, val});
            }
        }
        sort(vec.begin(), vec.end(), [](const P &p1, const P &p2){
            if(p1.col<p2.col){
                return true;
             }
             else if(p1.col==p2.col){
                return p1.row<p2.row;
             }
             else{
                return false;
             }
        });
        cout << m << " " << n << "\n";
        int actCol=1;
        int actP=0;
        vector<pii> ans;
        while(actCol<=m){
            while(actP<vec.size() && vec[actP].col==actCol){
                ans.push_back({vec[actP].row+1, vec[actP].val});
                actP++;
            }
            cout << ans.size();
            if(ans.size()>0) cout << " " << ans[0].f;
            for(int i=1; i<ans.size(); i++){
                cout << " " << ans[i].f;
            }
            cout << "\n";
            if(ans.size()>0) cout << ans[0].s;
            for(int i=1; i<ans.size(); i++){
                cout << " " << ans[i].s;
            }
            cout << "\n";
            actCol++;
            ans.clear();
        }
    }
    return 0;
}
