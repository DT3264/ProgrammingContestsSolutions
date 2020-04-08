#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    string str;
    cin >> cases;
    int actCase=1;
    while(cases--){
        deque<string> deck, hand;
        for(int i=1; i<=27; i++){
            cin >> str;
            deck.push_back(str);
        }
        for(int i=1; i<=25; i++){
            cin >> str;
            hand.push_back(str);
        }
        int y=0;
        for(int i=0; i<3; i++){
            string card = deck.back();
            deck.pop_back();
            int val = (card[0]>='2' && card[0]<='9' ? card[0]-'0' : 10);
            y+=val;
            val=10-val;
            while(val-->0) deck.pop_back();
        }
        while(!hand.empty()){
            deck.push_back(hand.front());
            hand.pop_front();
        }
        while(y-->1) deck.pop_front();
        cout << "Case " << (actCase++) << ": " << deck.front() << "\n";
    }
	return 0;
}
