#include<stdio.h>
bool vis[100000];
int cont;
int main (){
    int n, m, z;
    int tN, tM;
    scanf("%d%d%d", &n, &m, &z);
    tN=n, tM=m;
    while(tN<=z){
        vis[tN]=true;
        tN+=n;
    }
    while(tM<=z){
        if(vis[tM]){
            cont++;
        }
        tM+=m;
    }
    printf("%d", cont);
    return 0;
}
