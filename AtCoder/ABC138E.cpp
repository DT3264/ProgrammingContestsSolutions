#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> vec[27];

ll binSearch(ll lastPos, ll vecPos){
    ll left=0, right=vec[vecPos].size()-1;
    ll toReturn=-1;
    while(left<=right){
        ll mid=left+(right-left)/2;
        if(vec[vecPos][mid]>lastPos){
            toReturn=vec[vecPos][mid];
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return toReturn;
}

int main(){
    ll i, j;
    string s, t;
    cin >> s >> t;
    ll sLen=s.length();
    ll tLen=t.length();
    for(i=0; i<sLen; i++){
        vec[s[i]-'a'].push_back(i);
    }
    ll rounds=0;
    ll lastPos=-1;
    bool can=true;
    for(i=0; i<tLen && can; i++){
        ll vecPos=t[i]-'a';
        if(vec[vecPos].size()==0){
            can=false;
            continue;
        }
        ll nextPos=binSearch(lastPos, vecPos);
        if(nextPos==-1){
            rounds++;
            lastPos=vec[vecPos][0];
        }
        else{
            lastPos=nextPos;
        }
    }
    if(can){
        cout << rounds*sLen+lastPos+1 << "\n";
    }
    else{
        cout << "-1\n";
    }
}
