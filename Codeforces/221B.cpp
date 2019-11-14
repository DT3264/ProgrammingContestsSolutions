#include<bits/stdc++.h>
using namespace std;
int n;
bool onN[10];
vector<int> vec;
string toString(int i){
    stringstream ss;
    ss << i;
    return ss.str();
}
int main(){
    scanf("%d", &n);
    string s = toString(n);
    for(char c : s){
        onN[c-'0']=true;
    }
    for(int i=1; i<=sqrt(n); i++) {
        if(n%i == 0){
            if(n/i == i){
                vec.push_back(i);
            }
            else{
                vec.push_back(i);
                vec.push_back(n/i);
            }
        }
    }
    string s2;
    int ans=0;
    for(int x : vec){
        bool same=false;
        s2=toString(x);
        for(char c : s2){
            if(onN[c-'0']){
                same=true;
                break;
            }
        }
        if(same){
            ans++;
        }
    }
    printf("%d\n", ans);
}