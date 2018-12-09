#include<stdio.h>
using namespace std;

int a, hh, mm;
bool notluckHour(){
    return hh!=7 && hh!=17;
}
bool notLuckMinute(){
    return mm!=7 && mm!=17 && mm!=27 && mm!=37 && mm!=47 && mm!=57;
}

int main(){
    scanf("%d %d %d", &a, &hh, &mm);
    int buttonPress=0;
    while(notluckHour() && notLuckMinute()){
        mm-=a;
        if(mm<0){
            mm = 60+mm;
            hh--;
            if(hh==-1) hh=23;
        }
        buttonPress++;
    }
    printf("%d", buttonPress);
    return 0;
}
