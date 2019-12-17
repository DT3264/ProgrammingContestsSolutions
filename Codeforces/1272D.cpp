#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> vec;
int main(){
    int n, t, i, j;
    cin >> n;
    cin >> t;
    vec.clear();
    vec.push_back(vector<int>());
    vec[0].push_back(t);
    n--;
    vector<int> actualVec;
    while(n--){
        cin >> t;
        int vecPos = vec.size()-1;
        int intVecPos = vec[vecPos].size()-1;
        if(vec[vecPos][intVecPos]<t){
            vec[vecPos].push_back(t);
        }
        else{
            vec.push_back(vector<int>());
            vecPos++;
            vec[vecPos].push_back(t);
        }
    }
    int ans=0;
    if(vec.size()==1){
        ans = vec[0].size();
    }
    for(i=0; i<vec.size()-1; i++){
        //ans = max(ans, vec[i].size());
        int vecLen = vec[i].size();
        int vec2Len = vec[i+1].size();
        ans = max(ans, vecLen);
        ans = max(ans, vec2Len);
        if(vecLen>1){
            if(vec[i][vecLen-2]<vec[i+1][0]){///1 X - 3
                ans = max(ans, vecLen+vec2Len-1);
            }
        }
        if(vec2Len>1){
            if(vec[i][vecLen-1]<vec[i+1][1]){///4 - X 5
                ans = max(ans, vecLen+vec2Len-1);
            }
        }
    }
    cout << ans << "\n";
}
