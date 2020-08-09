#include <bits/stdc++.h>
using namespace std;
char mapa[2001][2001];
int rows[2001][2001];
int cols[2001][2001];
int main(){
    int i, j, k;
    int n, m;
    scanf("%d%d", &n, &m);
    for(i=0; i<n; i++){
        scanf("%s", mapa[i]);
    }
    int lastValid=0, validCount=0;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(mapa[i][j]=='#'){
                for(k=lastValid; k<j && j>=0; k++){
                    cols[i][k]=validCount;
                }
                validCount=0;
                lastValid=j+1;
            }
            else{
                validCount++;
            }
        }
        for(k=lastValid; k<j; k++){
            cols[i][k]=validCount;
        }
        lastValid=0;
        validCount=0;
    }
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            if(mapa[j][i]=='#'){
                for(k=lastValid; k<j && j>=0; k++){
                    rows[k][i]=validCount;
                }
                validCount=0;
                lastValid=j+1;
            }
            else{
                validCount++;
            }
        }
        for(k=lastValid; k<j; k++){
            rows[k][i]=validCount;
        }
        lastValid=0;
        validCount=0;
    }
    int ans=0;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            ans=max(ans, rows[i][j]+cols[i][j]-1);
        }
    }
    printf("%d\n", ans);
}
