#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, p, q, i, j;
    string s;
    scanf("%d%d%d",&n,&p,&q);
    cin >> s;
    vector<string> ans;
    if(p>q){
        swap(p, q);
    }
    bool pTurn=true;
    int pos=0;
    while(pos<n){
        if((n-pos)%q==0) pTurn=false;
        if(pTurn){
            ans.push_back(s.substr(pos, p));
            pos+=p;
        }
        else{
            ans.push_back(s.substr(pos, q));
            pos+=q;
        }
    }
    if(ans.size()>0 && pos==n){
        cout << ans.size() << "\n";
        for(auto str : ans){
            cout << str << "\n";
        }
    }
    else{
        cout << "-1\n";
    }
return 0;
}
