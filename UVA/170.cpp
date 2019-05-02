#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

int getNextPile(char c){
    if(c>='2' && c<='9'){
        return (int)c-'0';
    }
    else if(c=='A'){
        return 1;
    }
    else if(c=='T'){
        return 10;
    }
    else if(c=='J'){
        return 11;
    }
    else if(c=='Q'){
        return 12;
    }
    else if(c=='K'){
        return 13;
    }
}

bool solve(){
    int i, j;
    vector<vector<string>> cards;
    vector<string> emptyVector;
    string actualPile;
    string actualCard;
    for(i=0; i<=12; i++){
        cards.push_back(emptyVector);
    }
    for(i=0; i<4; i++){
        getline(cin, actualPile);
        if(actualPile=="#"){
            return false;
        }
        stringstream ss = stringstream(actualPile);
        for(j=12; j>=0; j--){
            ss >> actualCard;
            cards[j].push_back(actualCard);
        }
    }
    int contCards=0;
    int nextPile=12;
    while(contCards<52 && cards[nextPile].size()>0){
        actualCard=cards[nextPile][0];
        cards[nextPile].erase(cards[nextPile].begin());
        nextPile=getNextPile(actualCard[0])-1;
        contCards++;
        //cout << "Actual card: " << actualCard << " / Next pile: " << nextPile << "\n";
    }
    cout << (contCards<10 ? "0" : "") << contCards << "," << actualCard << "\n";
    return true;
}

int main(){
    while(solve());
    return 0;
}
