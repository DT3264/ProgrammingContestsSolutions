#include<stdio.h>
#include<string.h>
int n, m;
bool visited[510][510];
char arr[510][510];
bool canReach;

bool isValid(int i, int j){
    return i>=0 && i<n && j>=0 && j<m;
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
void cubre(int x, int y){
    for(int i=0; i<4; i++){
        if(isValid(x+dx[i], y+dy[i])){
            if(arr[x+dx[i]][y+dy[i]] == '.'){
                arr[x+dx[i]][y+dy[i]]='D';
            }
        }
    }
}

void seekSheeps(int x, int y){
    if(visited[x][y]) return;
    else visited[x][y]=1;
    if(canReach) return;
    if(arr[x][y]=='S'){
        canReach = true;
        return;
    }
    if(arr[x][y]=='D') return;
    for(int i=0; i<4; i++){
        if(isValid(x+dx[i], y+dy[i])){
            seekSheeps(x+dx[i], y+dy[i]);
        }
    }
}

int main(){
    int i, j;
    scanf("%d%d", &n, &m);
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf(" %c", &arr[i][j]);
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(arr[i][j]=='W'){
                cubre(i, j);
            }
        }
    }
    for(i=0; i<n && !canReach; i++){
        for(j=0; j<m && !canReach; j++){
            if(arr[i][j]=='W'){
                seekSheeps(i, j);
            }
        }
    }
    if(!canReach){
        printf("Yes\n");
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                printf("%c", arr[i][j]);
            }
            printf("\n");
        }
    }
    else printf("No\n");
    return 0;
}
