#include<bits/stdc++.h>
#define f first
#define s second
#define vi vector<int>
#define pii pair<int, int>
#define ll long long
using namespace std;
void checkZero(char &c1, char &c2){
    if(c1=='0' && c2=='.'){
        c2='1';
    }
    else if(c1=='.' && c2=='0'){
        c1='1';
    }
}
void checkOne(char &c1, char &c2){
    if(c1=='1' && c2=='.'){
        c2='0';
    }
    else if(c1=='.' && c2=='1'){
        c1='0';
    }
}
void checkDiferent(char &c1, char &c2){
    if(c1=='.' && c2=='.'){
        c1='0';
        c2='1';
    }
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n, m;
    string str;
    cin >> n >> m >> str;
    bool can=false;
    if(n==m) can=false;///Never a sequence
    for(int i=0; i+m<n; i++){
        //cout << i << "," << i+m;
        checkZero(str[i], str[i+m]);
        checkOne(str[i], str[i+m]);
        checkDiferent(str[i], str[i+m]);
        if(str[i]!=str[i+m]){
            can=true;
        }
    }
    for(char &c:str){
        if(c=='.') c='0';
    }
    if(!can){
        cout << "No\n";
        //cout << str << "\n";
    }
    else{
        cout << str << "\n";
    }
    return 0;
}
