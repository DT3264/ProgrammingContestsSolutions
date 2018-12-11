#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

vector<int> vec[110];
int bestTime[110];
int n, e, t;
int saved;

void submarino(int ind, int actualTime){
   if(ind==n) return;
   if(actualTime<bestTime[ind] || bestTime[ind]==-1){
        if(bestTime[ind]==-1) saved++;
        bestTime[ind]=actualTime;
   }
   else return;
   for(int i=0; i<vec[ind].size(); i++){
        if(actualTime+1<t)
        submarino(vec[ind][i], actualTime+1);
   }
}

int main(){
    memset(bestTime, -1, sizeof(bestTime));
    scanf("%d%d%d", &n, &e, &t);
    int a, b;
    for(int i=0; i<e; i++){
        scanf("%d %d", &a, &b);
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for(int i=0; i<vec[n].size(); i++){
        submarino(vec[n][i], 1);
    }
    printf("%d", saved);
return 0;
}