#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        vector<int> vec;
        map<int, char> mapa;
        sort(s.begin(), s.end(), [](char c1, char c2){
            if(toupper(c1)==toupper(c2)){
                return c1<c2;
             }
             return toupper(c1)<toupper(c2);
        });
        int actInd=0;
        mapa[0]=s[0];
        vec.push_back(0);
        for(int i=1; i<s.size(); i++){
            if(s[i]==s[i-1]){
                vec.push_back(actInd);
            }
            else{
                mapa[++actInd]=s[i];
                vec.push_back(actInd);
            }
        }
        do{
            for(int x : vec){
                cout << mapa[x];
            }
            cout << "\n";
		}while(next_permutation(vec.begin(),vec.end()));
    }
	return 0;
}
