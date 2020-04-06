#include<bits/stdc++.h>
#define f first
#define s second
#define pii pair<int, int>
using namespace std;
struct Pos{
    int x, y, step;
};
int n, m;
char mapa[1000][1000];
int memo[1000][1000];
int dX[4]={0, 0, -1, 1};
int dY[4]={-1, 1, 0, 0};
bool isValid(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}
int getVal(char c){
    return c=='.' ? 0 : c-'0';
}
void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%2.1d ", memo[i][j]);
        }
        printf("\n");
    }
}
int main(){
    pii ini, fin;
    scanf("%d%d", &n, &m);
    scanf("%d%d", &ini.f, &ini.s);
    scanf("%d%d", &fin.f, &fin.s);
    ini.f--;ini.s--;
    fin.f--;fin.s--;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf(" %c", &mapa[i][j]);
        }
    }
    memset(memo, -1, sizeof(memo));
    queue<Pos> q;
    Pos aPos;
    q.push({ini.f, ini.s, 0});
    memo[ini.f][ini.s]=0;
    while(!q.empty()){
        aPos=q.front();
        q.pop();
        ///Si ya pasé por ahí con algo diferente en un movimiento anterior
        if(memo[aPos.x][aPos.y]!=aPos.step){
            continue;
        }
        for(int i=0; i<4; i++){
            int nX=aPos.x+dX[i];
            int nY=aPos.y+dY[i];
            if(isValid(nX, nY) && mapa[nX][nY]!='#'){
                int nPos=aPos.step+getVal(mapa[nX][nY])+1;
                if(memo[nX][nY]==-1 || memo[nX][nY]>nPos){
                    q.push({nX, nY, nPos});
                    memo[nX][nY]=nPos;
                }
            }
        }
        //print();
        //system("pause");
    }
    printf("%d\n", memo[fin.f][fin.s]);
    return 0;
}
