#include "bits/stdc++.h"
using namespace std;
struct card{
    int n;
    char c;
};
bool sortByNumber(card a, card b){
    return a.n<b.n;
}
int main() {
    int n, i;
    int s=0, m=0, p=0;
    card cards[3];
    for(i=0; i<3; i++){
        scanf("%d%c", &cards[i].n, &cards[i].c);
    }
    sort(cards, cards+3, sortByNumber);
    int shuntsu=1;
    int maxShuntsu=1;
    for(i=0; i<2; i++){
        if(cards[i].n+1==cards[i+1].n && cards[i].c==cards[i+1].c){
            shuntsu++;
        }
        else{
            maxShuntsu=max(shuntsu, maxShuntsu);
            shuntsu=1;
        }
    }
    maxShuntsu=max(shuntsu, maxShuntsu);
    int koutsu=1;
    int maxKoutsu=1;
    for(i=1; i<=2; i++){
        if(cards[i].c==cards[i-1].c && cards[i].n==cards[i-1].n){
            koutsu++;
        }
        else{
            maxKoutsu=max(maxKoutsu, koutsu);
            koutsu=1;
        }
    }
    maxKoutsu=max(maxKoutsu, koutsu);
    if(cards[0].c==cards[2].c && cards[0].n+2==cards[2].n){
        maxKoutsu=max(maxKoutsu, 2);
    }
    if(cards[0].c==cards[1].c && cards[0].n+2==cards[1].n){
        maxKoutsu=max(maxKoutsu, 2);
    }
    if(cards[0].c==cards[1].c && cards[0].n+1==cards[1].n){
        maxKoutsu=max(maxKoutsu, 2);
    }
    if(cards[0].c==cards[2].c && cards[0].n+1==cards[2].n){
        maxKoutsu=max(maxKoutsu, 2);
    }
    if(cards[1].c==cards[2].c && cards[1].n+2==cards[2].n){
        maxKoutsu=max(maxKoutsu, 2);
    }
    if(cards[1].c==cards[2].c && cards[1].n+1==cards[2].n){
        maxKoutsu=max(maxKoutsu, 2);
    }
    int ans=3;
    ans=min(ans, 3-maxShuntsu);
    ans=min(ans, 3-maxKoutsu);
    printf("%d\n", ans);
    return 0;
}
