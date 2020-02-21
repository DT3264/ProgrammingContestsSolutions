#include<bits/stdc++.h>
using namespace std;
int getDiff(int num, int l, int r){
    if(l==-1) l=num;
    if(r==-1) r=num;
    //printf("%d - %d\n", l, r);
    return abs(r-l);
}
bool nextToNot(int ind, vector<int> &vec, int n){
    if(ind-1>=0 && vec[ind-1]==-1) return true;
    if(ind+1<n && vec[ind+1]==-1) return true;
    return false;
}
int main(){
    int cases;
    cin >> cases;
    while(cases--){
        int n, sum=0, cant=0;
        cin >> n;
        vector<int> vec(n);
        for(int &x : vec){
            cin >> x;
            if(x!=-1){
                sum+=x;
                cant++;
            }
        }
        int minN=1e9;
        int maxN=0;
        for(int i=0; i<n; i++){
            if(vec[i]!=-1 && nextToNot(i, vec, n)){
                minN=min(minN, vec[i]);
                maxN=max(maxN, vec[i]);
            }
        }
        int k=(minN+maxN)/2;
        int maxDiff=0;
        for(int i=1; i<n; i++){
            maxDiff=max(maxDiff, getDiff(k, vec[i], vec[i-1]));
        }
        printf("%d %d\n", maxDiff, k);
        //system("pause");
    }
    return 0;
}
