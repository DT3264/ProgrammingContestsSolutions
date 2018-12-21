#include <stdio.h>
#include <iostream>
using namespace std;

string one = "one";
string two = "two";
string three = "three";
string mainS;

int main(){
    int n, i, j, missOne, missTwo, missThree;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        cin >> mainS;
        missOne = 0;
        missTwo = 0;
        missThree = 0;
        if(mainS.length()==3){
            ///prueba 1 y 2
            for(j=0; j<mainS.length(); j++){
                if(mainS[j]!=one[j]) missOne++;
                if(mainS[j]!=two[j]) missTwo++;
            }
            printf(missOne<=missTwo ? "1\n" : "2\n");
        }
        else{
            printf("3\n");
        }
    }
    return 0;
}
