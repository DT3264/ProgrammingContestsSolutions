#include<bits/stdc++.h>
using namespace std;
bool arePalindromes(string &s1, string &s2){
    for(int i=0; i<s1.size(); i++){
        if(s1[i]!=s2[s2.size()-1-i]) return false;
    }
    return true;
}
bool isPalindrome(string &s){
    for(int i=0; i<s.size(); i++){
        if(s[i]!=s[s.size()-1-i]) return false;
    }
    return true;
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    int letters=0;
    cin >> n >> m;
    vector<string> vec(n);
    vector<string> palindromes;
    string middle="";
    for(string &s : vec) cin >> s;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(vec[i].size()>0 && vec[j].size()>0 && arePalindromes(vec[i], vec[j])){
                palindromes.push_back(vec[i]);
                letters+=m*2;
                vec[i]="";
                vec[j]="";
            }
        }
    }
    for(int i=0; i<n; i++){
        if(vec[i]!="" && isPalindrome(vec[i])){
            middle=vec[i];
            letters+=m;
            break;
        }
    }
    cout << letters << "\n";
    for(int i=0; i<palindromes.size(); i++){
        cout << palindromes[i];
    }
    cout << middle;
    for(int i=palindromes.size()-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            cout << palindromes[i][j];
        }
    }
    cout << "\n";
    return 0;
}
