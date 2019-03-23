#include<stdio.h>
#include<bitset>
#include<iostream>
using namespace std;
bitset<32> shift(int l1, int l2, bitset<32> bs){
    for(int i=0; i<8; i++){
        int temp=bs[l1+i];
        bs[l1+i]=bs[l2+i];
        bs[l2+i]=temp;
    }
    return bs;
}
int main(){
    int a;
    ///The conversion from one endian to other is
    ///[0-7b]  [8-15b] [16-23b][24-31b]->
    ///[24-31b][16-23b][8-15b] [0-8b]
    while(cin >> a){
        bitset<32> bs(a);
        bs=shift(0, 24, bs);
        bs=shift(8, 16, bs);
        cout << a << " converts to " << (int)bs.to_ulong() << endl;
    }
}
