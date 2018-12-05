#include<stdio.h>
char year[4];
bool equalDigits(){
    int i, j;
    bool hasEqualDigits = false;
    for(i=0; i<3; i++){
        for(j=i+1; j<4; j++){
            ///printf("%c ?= %c\n", year[i], year[j]);
            if(year[i]==year[j]) hasEqualDigits = true;
        }
    }
    return hasEqualDigits;
}

void addYear(int n){
    if(n<0) return;
    year[n]++;
    if(year[n]>'9'){
        year[n]='0';
        addYear(n-1);
    }
}

int main(){
    scanf("%s", year);
    addYear(3);
    while(equalDigits()){
        ///printf("%s\n", year);
        addYear(3);
    }
    printf("%s\n", year);
    return 0;
}
