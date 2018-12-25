#include<stdio.h>
char str[10000][6];

bool bothFree(int x, int y){
    //printf("%d -> %s\n", x, str[x]);
    return str[x][y]=='O' && str[x][y+1]=='O';
}

int main(){
    int n, i, j;
    scanf("%d", &n);
    bool seat=false;
    for(i=0; i<n; i++){
        scanf("%s", str[i]);
        if(!seat){
            if(bothFree(i, 0)){
                str[i][0]='+';
                str[i][1]='+';
                seat=true;
            }
            else if(bothFree(i, 3)){
                str[i][3]='+';
                str[i][4]='+';
                seat=true;
            }
        }
    }
    if(!seat){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        for(i=0; i<n; i++){
            printf("%s\n", str[i]);
        }
    }
    return 0;
}
