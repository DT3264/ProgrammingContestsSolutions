#include<stdio.h>
#include<math.h>
#include<bitset>
#include<queue>
using namespace std;
queue<int> games;
int cont;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        cont=0;
        int n, m, i, w;
        scanf("%d%d", &n, &m);
        bitset<1024> bs;
        for(i=0; i<m; i++){
            scanf("%d", &w);
            w--;
            bs[w]=true;
        }
        for(i=0; i<pow(2, n); i+=2){
            bool p1=!bs[i];
            bool p2=!bs[i+1];
            if(p1+p2==1){
                cont++;
            }
            games.push(p1+p2);
        }
        while(games.size()>=2){
            bool g1=games.front();
            games.pop();
            bool g2=games.front();
            games.pop();
            if(g1+g2==1){
                cont++;
            }
            games.push(g1+g2);
        }
        games.pop();
        printf("%d\n", cont);
    }
}
