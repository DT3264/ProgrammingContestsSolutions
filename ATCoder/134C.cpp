#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> vec;
    int n, i, t;
    int maxN, beforeMax;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &t);
        vec.push_back(t);
    }
    vector<int> tmpVec = vec;
    sort(tmpVec.begin(), tmpVec.end());
    maxN=tmpVec[n-1];
    beforeMax=tmpVec[n-2];
    for(i=0; i<n; i++){
        if(vec[i]!=maxN){
            printf("%d\n", maxN);
        }
        else if(vec[i]==maxN){
            printf("%d\n", beforeMax);
        }
    }
    return 0;
}
