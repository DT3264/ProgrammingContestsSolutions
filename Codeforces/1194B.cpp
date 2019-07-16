#include "bits/stdc++.h"
using namespace std;
struct pos{
    int x;
    int y;
};
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int q;
    int rows[50001];
    int cols[400001];
    map<pair<int, int>, bool> intersects;
    scanf("%d", &q);
    while(q--){
        int n, m, i, j;
        char tC;
        scanf("%d%d", &n, &m);
        intersects.clear();
        for(i=0; i<n; i++){
            rows[i]=0;
        }
        for(i=0; i<m; i++){
            cols[i]=0;
        }
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                scanf(" %c", &tC);
                if(tC=='*'){
                    rows[i]++;
                    cols[j]++;
                    intersects[{i, j}]=true;
                    //printf("intersects at %d, %d\n", i, j);
                }
            }
        }
        int ans=0;
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                //printf("actualAns: %d\n", ans);
                if(intersects[{i, j}]){
                    ans=max(ans, (rows[i]+cols[j])-1);
                    //printf("intersect at %d, %d: %d\n", i, j, ans);
                }
                else{
                    ans=max(ans, (rows[i]+cols[j]));
                    //printf("white at %d, %d: %d\n", i, j, ans);
                }
            }
        }
        printf("%d\n", (n+m-1)-ans);
    }
    return 0;
}
