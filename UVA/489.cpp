#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str1, str2;
    int n;
    while(cin >> n && n!=-1){
        vector<bool> used(27, 0);
        vector<int> buck(27, 0);
        cin >> str1 >> str2;
        for(char c : str1){
            buck[c-'a']++;
        }
        int remainLetters=str1.size();
        int remainTries=7;
        for(char c : str2){
            if(!used[c-'a']){
                if(buck[c-'a']>0){
                    remainLetters-=buck[c-'a'];
                    if(remainLetters==0){
                        break;
                    }
                }
                else{
                    remainTries--;
                    if(remainTries==0){
                        break;
                    }
                }
                used[c-'a']=1;
            }
        }
        cout << "Round " << n << "\n";
        if(remainTries<=0){
            cout << "You lose.";
        }
        else if(remainLetters==0){
            cout << "You win.";
        }
        else if(remainLetters>0 && remainTries>0){
            cout << "You chickened out.";
        }
        cout << "\n";

    }
	return 0;
}
