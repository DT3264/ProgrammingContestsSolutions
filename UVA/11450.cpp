#include<bits/stdc++.h>
using namespace std;
int dineroTotal;
int grupos;
int dp[200][2000];
vector<int> ropa[20];
int genera(int pos, int dinero){
    if(dinero>dineroTotal){
        return -1;
    }
    if(pos==grupos){
        return dinero;
    }
    if(dp[pos][dinero]!=-1){
        return dp[pos][dinero];
    }
    int bestAns=-1;
    for(int x : ropa[pos]){
        ///Suponiendo que tomamos esa prenda
        bestAns=max(bestAns, genera(pos+1, dinero+x));
    }
    dp[pos][dinero]=bestAns;
    return bestAns;
}
int main(){
    int cases;
    cin >> cases;
    while(cases--){
        memset(dp, -1, sizeof(dp));
        int grupoLen;
        cin >> dineroTotal >> grupos;
        for(int i=0; i<grupos; i++){
            cin >> grupoLen;
            ropa[i].resize(grupoLen);
            for(int &x : ropa[i]){
                cin >> x;
            }
        }
        int ans=genera(0, 0);
        if(ans!=-1){
            printf("%d\n", ans);
        }
        else{
            printf("no solution\n");
        }
    }
    return 0;
}
