#include<stdio.h>
#include<algorithm>
char arr[400][400];
int mapa[400][400];
int main (){
    int n, i, j;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf(" %c", &arr[i][j]);
        }
    }
    char cX = arr[n-1][n-1];
    char c0 = arr[n/2][0];
    ///printf("%c %c", cX, c0);
    bool isX = true;
    for(i=0; i<n && isX; i++){
        if(arr[i][i]!=cX || arr[i][n-1-i]!=cX) isX=false;
        mapa[i][i] = 1;
        mapa[i][n-1-i]=1;
    }
    for(i=0; i<n && isX; i++){
        for(j=0; j<n && isX; j++){
            if(mapa[i][j]==0 && (arr[i][j]!=c0 || arr[i][j]==cX)) isX=false;
            ///printf("%d ", mapa[i][j]);
        }
        ///printf("\n");
    }
    printf(isX ? "YES":"NO");
    return 0;
}
