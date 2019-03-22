#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;
int n;
string arr;
map<string, int> mapa;
int cont=1;
void bin(int pos){
    if(pos==n){
        for(int i=1; i<arr.size(); i++){
            if(arr[i]<=arr[i-1]){
                return;
            }
        }
        mapa[arr]=cont++;
        return;
    }
    for(int i=pos; i<26; i++){
        arr[pos]='a'+i;
        bin(pos+1);
    }
}

int main(){
    //freopen("in.txt", "r", stdin);
    for(int i=1; i<=5; i++){
        arr="a";
        for(int j=1; j<i; j++){
            arr+=arr[j-1]+1;
        }
        n=i;
        bin(0);
    }
    while(cin >> arr){
        cout << mapa[arr] << endl;
    }
}
