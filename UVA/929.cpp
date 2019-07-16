#include<bits/stdc++.h>
#define isValid(x, y) x>=0 && x<n && y>=0 && y<m
using namespace std;
struct pos{
    int x;
    int y;
    int cost;
};
struct posComparator {
    int operator() (const pos &p1, const pos &p2){
        return p1.cost > p2.cost;
    }
};
int arr[1000][1000];
int mark[1000][1000];
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int mazes;
    int dX[4]={0, 0, -1, 1};
    int dY[4]={-1, 1, 0, 0};
    int n, m;
    int i, j;
    scanf("%d", &mazes);
    while(mazes--){
        memset(mark, -1, sizeof(mark));
        scanf("%d%d", &n, &m);
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                scanf("%d", &arr[i][j]);
            }
        }
        priority_queue<pos, vector<pos>, posComparator> pQueue;
        pQueue.push({0, 0, arr[0][0]});
        pos aPos;
        int nX, nY, nC;
        while(!pQueue.empty()){
            aPos=pQueue.top();
            pQueue.pop();
            if(mark[aPos.x][aPos.y]==-1 || mark[aPos.x][aPos.y]>aPos.cost){
                mark[aPos.x][aPos.y]=aPos.cost;
                int nX, nY;
                for(i=0; i<4; i++){
                    nX=aPos.x+dX[i];
                    nY=aPos.y+dY[i];
                    if(isValid(nX, nY)){
                        nC=aPos.cost+arr[nX][nY];
                        if(mark[nX][nY]==-1 || mark[nX][nY]>nC){
                            pQueue.push({nX, nY, nC});
                        }
                    }
                }
            }
        }
        printf("%d\n", mark[n-1][m-1]);
    }
    return 0;
}
