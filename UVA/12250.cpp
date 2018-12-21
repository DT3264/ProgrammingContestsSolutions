#include <stdio.h>
#include <iostream>
using namespace std;

string mainString;
string english = "HELLO";
string spanish = "HOLA";
string german  = "HALLO";
string french  = "BONJOUR";
string italian = "CIAO";
string rusian  = "ZDRAVSTVUJTE";

int contDifChars;
int main(){
    char t;
    int i=1;
    bool noEs;
    while(cin >> mainString && mainString[0]!='#'){
        if(mainString == english) printf("Case %d: ENGLISH\n", i);
        else if(mainString == spanish) printf("Case %d: SPANISH\n", i);
        else if(mainString == german) printf("Case %d: GERMAN\n", i);
        else if(mainString == french) printf("Case %d: FRENCH\n", i);
        else if(mainString == italian) printf("Case %d: ITALIAN\n", i);
        else if(mainString == rusian) printf("Case %d: RUSSIAN\n", i);
        else printf("Case %d: UNKNOWN\n", i);
        i++;

    }
    return 0;
}
