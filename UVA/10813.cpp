#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
vector<vi> card;
bool haveBingoRow(int row){
    int marked=0;
    for(int i=0; i<5; i++){
        if(card[row][i]==-1) marked++;
    }
    return marked==5;
}
bool haveBingoColumn(int column){
    int marked=0;
    for(int i=0; i<5; i++){
        if(card[i][column]==-1) marked++;
    }
    return marked==5;
}
bool haveDiagonalBingo(){
    int markedMainDiag=0;
    int markedSecondDiag=0;
    for(int i=0; i<5; i++){
        if(card[i][i]==-1) markedMainDiag++;
        if(card[i][4-i]==-1) markedSecondDiag++;
    }
    return (markedMainDiag==5 || markedSecondDiag==5);
}
bool haveBingo(){
    bool isBingo=false;
    for(int i=0; i<5 && !isBingo; i++){
        if(haveBingoRow(i) || haveBingoColumn(i)) isBingo=true;
    }
    if(haveDiagonalBingo()) isBingo=true;
    return isBingo;
}
void mark(int val){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(card[i][j]==val){
                card[i][j]=-1;
                return;
            }
        }
    }
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases, val;
    cin >> cases;
    while(cases--){
        card.assign(5, vi(5, 0));
        vector<int> numbers(75);
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(i==2 && j==2){
                    card[i][j]=-1;
                    continue;
                }
                cin >> card[i][j];
            }
        }
        for(int &x : numbers){
            cin >> x;
        }
        int winnerAt=-1;
        for(int i=0; i<numbers.size() && winnerAt==-1; i++){
            int actualNumber=numbers[i];
            mark(actualNumber);
            if(haveBingo()){
                winnerAt=i+1;
            }
        }
        cout << "BINGO after " << winnerAt <<" numbers announced\n";
    }
	return 0;
}
