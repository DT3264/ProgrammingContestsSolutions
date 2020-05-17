#include<bits/stdc++.h>
#define f first
#define s second
#define vi vector<ll>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    stringstream ss;
    ll cases;
    cin >> cases;
    while(cases--){
        int n, t, m;
        cin >> n >> t >> m;
        int actTime=0;
        string actDir;
        vector<int> ans(m);
        queue<pii> left, right;
        for(int i=0; i<m; i++){
            cin >> actTime >> actDir;
            if(actDir[0]=='l'){
                left.push({actTime, i});
            }
            else{
                right.push({actTime, i});
            }
        }
        actTime=0;
        bool onLeft=true;
        int toAdd;
        int taken=0;
        while(!left.empty() || !right.empty()){
            int leftVal=left.size()>0 ? left.front().f : 1e9;
            int rightVal=right.size()>0 ? right.front().f : 1e9;
            int minVal=min(leftVal, rightVal);

            toAdd=1;
            if(minVal==leftVal && minVal<=actTime && !onLeft && actTime<rightVal){
                onLeft=true;
                actTime+=t;
            }
            else if(minVal==rightVal && minVal<=actTime && onLeft && actTime<leftVal){
                onLeft=false;
                actTime+=t;
            }
            if(onLeft){
                while(left.size()>0 && left.front().f<=actTime){
                    taken++;
                    ans[left.front().s]=actTime+t;
                    left.pop();
                    toAdd=t;
                    if(taken==n){
                        break;
                    }
                }
            }
            else{
                while(right.size()>0 && right.front().f<=actTime){
                    taken++;
                    ans[right.front().s]=actTime+t;
                    right.pop();
                    toAdd=t;
                    if(taken==n){
                        break;
                    }
                }
            }
            ///To the other side
            if(taken>0){
                onLeft=!onLeft;
                taken=0;
            }
            actTime+=toAdd;
        }
        for(int i=0; i<m; i++){
            cout << ans[i] << "\n";
        }
        if(cases>0){
            cout << "\n";
        }
    }
    return 0;
}
