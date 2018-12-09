#include<stdio.h>
using namespace std;
int main(){
    int x, y, i;
    char t;
    bool bnw = true;
    scanf("%d %d", &x, &y);
    for(i=0; i<x*y; i++){
        scanf(" %c", &t);
        if(t!='B' && t!='W' && t!='G') bnw=false;
    }
    printf(bnw ? "#Black&White\n" : "#Color\n");
    return 0;
}
