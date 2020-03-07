#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int> vec;
int dp[10001][101];
int getVal(int x){
    return ((x%k)+k)%k;
}
int calculate(int pos, int sum){
    if(pos==n){
        return sum==0;
    }
    if(dp[pos][getVal(sum)]!=-1){
        return dp[pos][getVal(sum)];
    }
    int can=0;
    can=max(can, calculate(pos+1, getVal(sum+vec[pos])));
    can=max(can, calculate(pos+1, getVal(sum-vec[pos])));
    return dp[pos][getVal(sum)]=can;
}
int main(){
    int cases;
    cin >> cases;
    while(cases-->0){
        cin >> n >> k;
        vec.resize(n);
        for(int &x:vec){
            cin >> x;
        }
        memset(dp, -1, sizeof(dp));
        bool divisible=calculate(0, 0);
        printf("%s\n", (divisible ? "Divisible" : "Not divisible"));
    }
    return 0;
}
