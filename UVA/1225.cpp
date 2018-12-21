#include<stdio.h>
#include<iostream>
using namespace std;

char s[5];
int numBuck[10];
int lastPos;

void sumaVals(){
    int z;
    for(z=0; z<=lastPos && s[z]=='0'; z++);
    for(z=z; z<=lastPos; z++){
        //printf("%d-", s[z]-'0');
        numBuck[s[z]-'0']++;
    }
    //printf("\n");
}

void nextVal(int pos){
    if(pos<0) return;
    if(pos==0 && numBuck[0]=='0') return;
    s[pos]--;
    if(s[pos]<'0'){
        s[pos]='9';
        nextVal(pos-1);
    }
}

int main(){
    int i, j, n;
    scanf("%d", &n);
    int pot = 1;
    int num=0;
    for(i=0; i<n; i++){
        for(j=0; j<10; j++) numBuck[j]=0;
        for(j=0; j<5; j++) s[j]='a';
        num=0;
        pot=1;
        scanf("%s", s);
        for(j=0; j<5; j++){
            if(s[j]>='0' && s[j]<='9'){
                lastPos = j;
            }
        }
        for(j=lastPos; j>=0; j--){
            num += (s[j]-'0')*pot;
            pot*=10;
        }
        while(num-->0){
            sumaVals();
            nextVal(lastPos);
        }

        for(j=0; j<10; j++){
            printf("%d", numBuck[j]);
            printf(j<=8 ? " " : "");
        }
        printf("\n");
    }
    return 0;
}