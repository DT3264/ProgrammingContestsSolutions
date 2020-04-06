#include<bits/stdc++.h>
using namespace std;
int n, m;
int dp[501];
bool mapa[501][501];
void updatePos(int row){
    int consec=0;
    int maxConsec=0;
    for(int i=0; i<m; i++){
        if(mapa[row][i]){
            consec++;
        }
        else{
            maxConsec=max(maxConsec, consec);
            consec=0;
        }
    }
    maxConsec=max(maxConsec, consec);
    dp[row]=maxConsec;
}
int main(){
    int q, val;
    scanf("%d%d%d", &n, &m, &q);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &val);
            mapa[i][j]=(val==1 ? true : false);
        }
        updatePos(i);
    }
    int x, y;
    for(int i=0; i<q; i++){
        scanf("%d%d", &x, &y);
        x--;
        y--;
        mapa[x][y]=!mapa[x][y];
        updatePos(x);
        int ans=0;
        for(int i=0; i<n; i++){
            ans=max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
