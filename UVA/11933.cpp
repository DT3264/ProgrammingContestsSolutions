#include<stdio.h>
#include<iostream>
#include<bitset>
using namespace std;
int main(){
    int n;
    while(cin >> n && n!=0){
        bool toN1=true;
        bitset<32> bs(n), n1, n2;
        for(int i=0; i<32; i++){
            if(bs[i]){
                if(toN1){
                    n1[i]=1;
                }
                else{
                    n2[i]=1;
                }
                toN1=!toN1;
            }
        }
        cout << n1.to_ulong() << " " << n2.to_ulong() << endl;
    }
}
