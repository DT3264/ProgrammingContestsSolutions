#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    bool ans;
    ans=(s[0]==s[1] && s[1]!=s[2] && s[2]==s[3]);
    cout << (ans ? "Yes" : "No") << "\n";
    return 0;
}
