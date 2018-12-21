#include<stdio.h>
int x, y;
int i, j;
char t;
char arr[100][100];
int prob[100][100];

void mine(){
    if(i-1>=0 && j-1>=0) prob[i-1][j-1]++;
    if(i-1>=0) prob[i-1][j]++;
    if(i-1>=0 && j+1<y) prob[i-1][j+1]++;
    ///
    if(j-1>=0) prob[i][j-1]++;
    if(j+1<y) prob[i][j+1]++;
    ///
    if(i+1<x && j-1>=0) prob[i+1][j-1]++;
    if(i+1<x) prob[i+1][j]++;
    if(i+1<x && j+1<y) prob[i+1][j+1]++;
}

void printPath(){
    int i, j;
    for(i=0; i<x; i++){
        for(j=0; j<y; j++){
            if(arr[i][j]=='*') printf("*");
            else printf("%d", prob[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int cont=1;
    while(scanf("%d %d", &x, &y) && x!=0 && y!=0){
        if(cont>1) printf("\n");
        for(i=0; i<x; i++){
            for(j=0; j<y; j++){
                prob[i][j]=0;
            }
        }
        printf("Field #%d:\n", cont++);
        for(i=0; i<x; i++){
            for(j=0; j<y; j++){
                scanf(" %c", &arr[i][j]);
                if(arr[i][j]=='*'){
                    mine();
                }
            }
        }
        printPath();
    }
    return 0;
}
