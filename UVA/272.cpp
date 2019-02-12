#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main(){
    freopen("in.txt", "r", stdin);
    int i;
    bool toOpen=true;
    string str;
    while(getline(cin, str)){
        for(i=0; i<str.size(); i++){
            if(str[i]=='"'){
                if(toOpen){
                    printf("``");
                }
                else{
                    printf("''");
                }
                toOpen=!toOpen;
            }
            else{
                printf("%c", str[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

