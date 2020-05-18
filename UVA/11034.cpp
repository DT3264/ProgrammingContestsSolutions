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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll cases;
    cin >> cases;
    while(cases--){
        int l, m;
        cin >> l >> m;
        l*=100;
        int actLen=0;
        string actDir;
        queue<int> left, right;
        for(int i=0; i<m; i++){
            cin >> actLen >> actDir;
            if(actDir[0]=='l'){
                left.push(actLen);
            }
            else{
                right.push(actLen);
            }
        }
        bool onLeft=true;
        int taken=0;
        int turns=0;
        while(!left.empty() || !right.empty()){
            taken=0;
            if(onLeft){
                while(left.size()>0 && left.front()+taken<=l){
                    taken+=left.front();
                    left.pop();
                }
            }
            else{
                while(right.size()>0 && right.front()+taken<=l){
                    taken+=right.front();
                    right.pop();
                }
            }
            ///To the other side
            onLeft=!onLeft;
            turns++;
        }
        cout << turns << "\n";
    }
    return 0;
}
