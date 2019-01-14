#include<stdio.h>
#include<string.h>
int n, m;
bool used[100001];
int buk[100001];
int cont;

void checkBuk(){
    for(int j=1; j<=n; j++){
        if(buk[j]>1){
            cont++;
        }
        buk[j]--;
    }
}

int main(){
    int i, t;
    int ans=0;
    scanf("%d%d", &n, &m);
    for(i=0; i<m; i++){
        scanf("%d", &t);
        ans=0;
        buk[t]++;
        if(buk[t]==1){
            cont++;
            if(cont==n){
                ans=1;
                cont=0;
                checkBuk();
            }
        }
        printf("%d", ans);
    }
    return 0;
}

