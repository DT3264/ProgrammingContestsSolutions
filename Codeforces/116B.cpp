#include<stdio.h>
#include<queue>
using namespace std;
struct pos{int x; int y;};
std::queue <pos> pigs;
int n, m;
char arr[11][11];
int eatPig(int x, int y){
    bool wAH = false;
    if(x-1>=0) if(arr[x-1][y]=='W' && !wAH)wAH = true, arr[x-1][y]='.'; 
    if(x+1<n)  if(arr[x+1][y]=='W' && !wAH) wAH = true, arr[x+1][y]='.'; 
    if(y-1>=0) if(arr[x][y-1]=='W' && !wAH) wAH = true, arr[x][y-1]='.'; 
    if(y+1<m)  if(arr[x][y+1]=='W' && !wAH) wAH = true, arr[x][y+1]='.'; 
    if(wAH)return 1;
    return 0;
}

int main (){
    int i, j, pigsAten=0;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf(" %c", &arr[i][j]);
            if(arr[i][j]=='P') pigs.push({i, j});
        }
    }
    while(!pigs.empty()){
        pos actualPig = pigs.front();
        pigs.pop();
        pigsAten+=eatPig(actualPig.x, actualPig.y);
    }
    printf("%d", pigsAten);
    return 0;
}
