#include<bits/stdc++.h>
using namespace std;
int getInt(){
    string line;
    getline(cin, line);
    return stoi(line);
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    string line;
    cases=getInt();
    while(cases--){
        vector<int> charPrice(256, 0);
        char actChar;
        int val;
        int lines;
        int price=0;
		lines=getInt();
        for(int i=0; i<lines; i++){
            //getline(cin, line);
            //stringstream ss(line);
            cin >> actChar >> val;
            //cout << actChar << " = " << val << "\n";
            charPrice[actChar]=val;
        }
        lines=getInt();
        for(int i=0; i<lines; i++){
            getline(cin, line);
            for(char c : line){
                price+=charPrice[c];
            }
        }
        //cout << "Amount: " << price << "\n";
        string total="";
        int countChars=0;
        while(price>0){
            countChars++;
            if(countChars==3){
                total+='.';
            }
            total+=(price%10)+'0';
            price/=10;
        }
        if(total.size()==2){
            total+=".0";
        }
        else if(total.size()==1){
            total+="0.0";
        }
        else if(total.size()==0){
            total+="00.0";
        }
        reverse(total.begin(), total.end());
        cout << total << "$" << "\n";
    }
	return 0;

}
