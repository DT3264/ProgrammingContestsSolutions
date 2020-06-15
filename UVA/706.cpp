#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
int n, m, s;
vector<string> word;
vector<string> vec;
void add(){
    for(int i=0; i<vec.size(); i++) word[i]+=vec[i];
}
void up(){
    int i=0, j=1, t=s;
    while(t-->0) vec[i][j++]='-';
}
void upLeft(){
    int i=1, j=0, t=s;
    while(t-->0) vec[i++][j]='|';
}
void upRight(){
    int i=1, j=m-1, t=s;
    while(t-->0) vec[i++][j]='|';
}
void mid(){
    int i=1+s, j=1, t=s;
    while(t-->0) vec[i][j++]='-';
}
void downLeft(){
    int i=n-2, j=0, t=s;
    while(t-->0) vec[i--][j]='|';
}
void downRight(){
    int i=n-2, j=m-1, t=s;
    while(t-->0) vec[i--][j]='|';
}
void down(){
    int i=n-1, j=1, t=s;
    while(t-->0) vec[i][j++]='-';
}
void addNumber(int val){
    vec.assign(n, string(m, ' '));
    if(word[0].size()>0){
        for(string &s : word){
            s+=' ';
        }
    }
    if(val==1){
        upRight();
        downRight();
    }
    else if(val==2){
        up();
        upRight();
        mid();
        downLeft();
        down();
    }
    else if(val==3){
        up();
        upRight();
        mid();
        downRight();
        down();
    }
    else if(val==4){
        upLeft();
        mid();
        upRight();
        downRight();
    }
    else if(val==5){
        up();
        upLeft();
        mid();
        downRight();
        down();
    }
    else if(val==6){
        up();
        upLeft();
        mid();
        downLeft();
        downRight();
        down();
    }
    else if(val==7){
        up();
        upRight();
        downRight();
    }
    else if(val==8){
        up();
        upLeft();
        upRight();
        mid();
        downLeft();
        downRight();
        down();
    }
    else if(val==9){
        up();
        upLeft();
        upRight();
        mid();
        downRight();
        down();
    }
    else if(val==0){
        up();
        upLeft();
        upRight();
        downLeft();
        downRight();
        down();
    }
    add();
}
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    string num;
    while(cin >> s >> num && s!=0){
        n=(2*s)+3, m=s+2;
        word.assign(n, "");
        for(char &c : num){
            addNumber(c-'0');
        }
        for(string &line : word) cout << line << "\n";
        cout << "\n";
    }
    return 0;

}
