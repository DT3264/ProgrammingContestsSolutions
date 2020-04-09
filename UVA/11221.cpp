#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cin.ignore();
    string in, str;
    for(int caseN=1; caseN<=n; caseN++){
        cout << "Case #" << caseN << ":" << endl;
        getline(cin, in);
        string str="";
        for(char c : in){
            if(c>='a' && c<='z'){
                str+=c;
            }
        }
        int n = sqrt(str.size());
        if(n*n!=str.size()){
            cout << "No magic :(\n";
        }
        else{
            bool isMagic=true;
            vector<string> vec(n);
            for(int i=0; i<str.size(); i++){
                vec[i/n]+=str[i];
            }
            vector<string> square(4);
            for(int i=0; i<n; i++){
                square[0]+=vec[0][i];
                square[1]+=vec[i][0];
            }
            for(int i=n-1; i>=0; i--){
                square[2]+=vec[i][n-1];
                square[3]+=vec[n-1][i];
            }
            for(int i=0; i<n; i++){
                if(square[0][i]==square[1][i] &&
                   square[1][i]==square[2][i] &&
                   square[2][i]==square[3][i]){

                }
                else{
                    isMagic=false;
                }
            }
            if(isMagic){
                cout << n << "\n";
            }
            else{
                cout << "No magic :(\n";
            }
        }
    }
	return 0;
}
