#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s1, s2, s3;
    cin >> n;
    while(n--){
        cin >> s1 >> s2 >> s3;
        bool can=true;
        for(int i=0; i<s1.length() && can; i++){
            if(s1[i]==s3[i]){
                continue;
            }
            else if(s2[i]==s3[i]){
                continue;
            }
            else can=false;
        }
        cout << (can ? "YES" : "NO") << "\n";
    }
    return 0;
}
