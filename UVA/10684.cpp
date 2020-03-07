#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    vector<int> vec;
    int dp[10001];
    while(cin >> n && n!=0){
        memset(dp, -1, sizeof(dp));
        vec.resize(n);
        for(int i=0; i<n; i++){
            cin >> vec[i];
            dp[i]=vec[i];
        }
        int sum=0;
        int maxN=-1;
        for(int i=0; i<vec.size(); i++){
            sum+=vec[i];
            dp[i]=max(dp[i], sum);
            sum=dp[i];
            maxN=max(maxN, sum);
        }
        if(maxN>0){
            printf("The maximum winning streak is %d.\n", maxN);
        }
        else{
            printf("Losing streak.\n");
        }
    }
    return 0;
}
