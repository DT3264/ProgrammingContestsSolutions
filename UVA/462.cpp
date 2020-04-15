#include<bits/stdc++.h>
#define vc vector<char>
using namespace std;
bool hasCard(vc &vec, char card){
    bool hasCard=false;
    for(char c : vec){
        if(c==card){
            hasCard=true;
        }
    }
    return hasCard;
}
char getHouseFromIndex(int index){
    if(index==0) return 'S';
    else if(index==1) return 'H';
    else if(index==2) return 'D';
    else if(index==3) return 'C';
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    while(getline(cin, line) && line!="0"){
        stringstream ss(line);
        ///0->Spades;1->Hears;2->Clubs;3->Diamonds
        int biggestHouse=0;
        int stoppedHouses=0;
        int points=0, partialPoints;
        string actCard;
        vector<vc> hand(4, vector<char>(0));
        while(ss >> actCard){
            //cout << "Card: " << actCard << "\n";
            if(actCard[1]=='S') hand[0].push_back(actCard[0]);
            else if(actCard[1]=='H') hand[1].push_back(actCard[0]);
            else if(actCard[1]=='D') hand[2].push_back(actCard[0]);
            else if(actCard[1]=='C') hand[3].push_back(actCard[0]);
            ///Rule 1
            if(actCard[0]=='A') points+=4;
            else if(actCard[0]=='K') points+=3;
            else if(actCard[0]=='Q') points+=2;
            else if(actCard[0]=='J') points+=1;
            //cout << points << "\n";
        }
        for(vc &house : hand){
            bool isStoppedHouse=false;
            if(  hasCard(house, 'A') ||
                (hasCard(house, 'K') && house.size()>=2) ||
                (hasCard(house, 'Q') && house.size()>=3)){
                isStoppedHouse=true;
            }
            if(isStoppedHouse) stoppedHouses++;
            if(hasCard(house, 'K') && house.size()==1) points--;///Rule 2
            if(hasCard(house, 'Q') && house.size()<=2) points--;///Rule 3
            if(hasCard(house, 'J') && house.size()<=3) points--;///Rule 4
            biggestHouse=max(biggestHouse, (int)house.size());
        }
        //cout << points << "**\n";
        partialPoints=points;///Points up to rule 4
        for(vc &house : hand){
            if(house.size()==2) points++;///Rule 5
            else if(house.size()<=1) points+=2;///Rule 6 & 7
        }
        //cout << points << " " << partialPoints << "*\n";
        if(points<14){
            cout << "PASS";
        }
        else if(stoppedHouses==4 && partialPoints>=16){
            cout << "BID NO-TRUMP";
        }
        else if(points>=14){
            int indexOfMax=-1;
            for(int i=0; i<4; i++){
                if(hand[i].size()==biggestHouse){
                    indexOfMax=i;
                    break;
                }
            }
            cout << "BID " << getHouseFromIndex(indexOfMax);
        }
        cout << "\n";
        //cout << "*" << line<< "*" <<"\n";
    }
	return 0;
}
