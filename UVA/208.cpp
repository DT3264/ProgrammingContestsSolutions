#include<stdio.h>
#include<string.h>
int n, a, b, i;
int streets[22][22];///Adjacency list
int route[22];///The actual route on the dfs
bool used[22];///If already visited on the dfs
bool canReach[22];///Can reach N from i? (avoid dead ends)
int contCases=1, contRoutes;
int pQueue[1000000];///Pseudo Queue
int left=0, right=0;///Bounds of pseudo queue

void getGoodStreets(){
    canReach[n]=true;
    pQueue[right++]=n;
    while(left!=right){
        int actualN=pQueue[left++];
        for(i=1; i<22; i++){
            if(streets[actualN][i]==1)
            if(!canReach[i]){
                canReach[i]=true;
                pQueue[right++]=i;
            }
        }
    }
}

void reachN(int street, int pos){
    if(used[street]){
        return;
    }
    route[pos]=street;
    if(street==n){
        contRoutes++;
        for(i=0; i<=pos; i++){
            printf("%d", route[i]);
            if(i<pos){
                printf(" ");
            }
        }
        printf("\n");
        return;
    }
    used[street]=true;
    for(int i=2; i<22; i++){
        if(streets[street][i]==1 && canReach[i]){
            reachN(i, pos+1);
        }
    }
    used[street]=false;
}

int main(){
    while(scanf("%d", &n)!=EOF){
        printf("CASE %d:\n", contCases++);
        contRoutes=0;
        memset(streets, 0, sizeof(streets));
        memset(canReach, 0, sizeof(canReach));
        while(scanf("%d%d", &a, &b) && a!=0 && b!=0){
            streets[a][b]=1;
            streets[b][a]=1;
        }
        getGoodStreets();
        reachN(1, 0);
        printf("There are %d routes from the firestation to streetcorner %d.\n", contRoutes, n);
    }
    return 0;
}

