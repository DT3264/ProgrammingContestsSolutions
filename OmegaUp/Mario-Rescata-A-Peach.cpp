#include<bits/stdc++.h>
using namespace std;
struct Pos{
    int x, y, time;
};

int n, m, c;
int memo[1001][1001];
int dX[4]={0, 0, -1, 1};
int dY[4]={-1, 1, 0, 0};
bool isValid(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}
void printMap(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%2.1d ", memo[i][j]);
        }
        printf("\n");
    }
}
int main(){
    char arr[1001][1001];
    queue<Pos> q;
    memset(memo, -1, sizeof(memo));
    Pos pF;
	vector<Pos> toPush;
    scanf("%d%d%d", &n, &m, &c);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf(" %c", &arr[i][j]);
            if(arr[i][j]=='E'){
                q.push({i, j, c});
                memo[i][j]=c;
            }
            else if(arr[i][j]=='M'){
                q.push({i, j, 0});
                memo[i][j]=0;
            }
            else if(arr[i][j]=='P'){
                pF={i, j, 0};
                //memo[i][j]=0;
            }
        }
    }
    Pos aP;
    int nX, nY, nC;
    while(!q.empty()){
        aP=q.front();
        q.pop();
		if(memo[aP.x][aP.y]<aP.time){
			continue;
		}
        for(int i=0; i<4; i++){
            nX=aP.x+dX[i];
            nY=aP.y+dY[i];
            nC=aP.time;///Lo que llevo ahorita
            if(isValid(nX, nY)){
                nC+=1+(arr[nX][nY]=='#');
                if(memo[nX][nY]==-1 || memo[nX][nY]>nC){///Si no he pasado o tengo algo mejor
                    q.push({nX, nY, nC});
                    memo[nX][nY]=nC;
                }
            }
        }
    }
    //printMap();
    printf("%d\n", memo[pF.x][pF.y]);
    return 0;
}