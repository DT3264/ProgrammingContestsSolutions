#include <iostream>

using namespace std;

int i, pivL=0, pivR;
int cards[1000];
int sejenaT=0, dimaT=0;
bool sejenasTurn=true;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> pivR;
    for(i=0; i<pivR; i++)
        cin >> cards[i];
    int bestChoice;
    pivR--;
    while(pivL!=pivR){
        if(cards[pivL]>cards[pivR]){
            bestChoice=cards[pivL];
            pivL++;
        }
        else{
            bestChoice=cards[pivR];
            pivR--;
        }
        if(sejenasTurn)
            sejenaT+=bestChoice;
        else
            dimaT+=bestChoice;
        sejenasTurn=!sejenasTurn;
    }
    if(sejenasTurn)
        sejenaT+=cards[pivL];
    else
        dimaT+=cards[pivL];
    cout << sejenaT << ' ' << dimaT;
    return 0;
}
