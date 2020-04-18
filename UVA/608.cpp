#include<bits/stdc++.h>
using namespace std;
struct Case{
    string left, right;
};
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        string left, right, balance;
        vector<Case> cases;
        vector<bool> validCoins(150, 0);
        vector<int> leftCount(150, 0), rightCount(150, 0);
        int unevenBalances=0;
        for(int i=0; i<3; i++){
            cin >> left >> right >> balance;
            if(balance=="even"){
                for(char c : left){
                    validCoins[c]=true;
                }
                for(char c : right){
                    validCoins[c]=true;
                }
            }
            if(balance=="up"){
                cases.push_back({left, right});
            }
            else if(balance=="down"){
                cases.push_back({right, left});
            }
        }
        for(int i=0; i<cases.size(); i++){
            Case actCase=cases[i];
            for(char c : actCase.left){
                if(!validCoins[c]){
                    leftCount[c]++;
                }
            }
            for(char c : actCase.right){
                if(!validCoins[c]){
                    rightCount[c]++;
                }
            }
        }
        char badCoin;
        bool isLight=true;
        for(char c='A'; c<='Z'; c++){
            if(leftCount[c]==cases.size()){
                badCoin=c;
                isLight=false;
            }
        }
        for(char c='A'; c<='Z'; c++){
            if(rightCount[c]==cases.size()){
                badCoin=c;
                isLight=true;
            }
        }
        cout << badCoin << " is the counterfeit coin and it is " << (isLight ? "light" : "heavy") << ".\n";
    }
	return 0;

}
