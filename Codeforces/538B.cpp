#include<bits/stdc++.h>
using namespace std;
int n;
int dp[1000001];
int prevN[1000001];
vector<int> quasi;
string num="0000000";
int getNum(){
    return stoi(num);
}
void generateQuasi(int pos){
    if(pos==num.size()){
        int num=getNum();
        if(num>0 && num<=n){
            quasi.push_back(num);
        }
        return;
    }
    num[pos]='0';
    generateQuasi(pos+1);
    num[pos]='1';
    generateQuasi(pos+1);
}
int main(){
    cin >> n;
    generateQuasi(0);
    memset(dp, -1, sizeof(dp));
    memset(prevN, -1, sizeof(prevN));
    dp[0]=0;//Marco mi estado inicial, si no, ninguno de delante puede seguir
    for(int i=1; i<=n; i++){
        for(int x : quasi){
            //i-x>=0: Con X puedo llegar hasta I o aproximarme sin pasarme
        	//dp[i]==-1: no he llegado ahí antes
        	//dp[i-x]+1 < dp[i]: si dado lo mejor en mi pos anterior + 1
        	//llego con algo mejor a lo que tengo
            if(i-x>=0 && (dp[i-x]+1<dp[i] || dp[i]==-1)){
                dp[i]=dp[i-x]+1;
                prevN[i]=i-x;
            }
        }
    }
    vector<int> ans;
    while(n>0){
        ans.push_back(n-prevN[n]);
        n=prevN[n];
    }
    cout << ans.size() << endl;
    for(int x : ans){
        cout << x << " ";
    }
    return 0;
}
