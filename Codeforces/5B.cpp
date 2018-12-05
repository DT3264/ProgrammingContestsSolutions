#include <iostream>
#include <stdio.h>

using namespace std;
string s[1000];
int sPos, maxLen, i, j;
int main()
{
    string tempS;
    while(getline(cin, tempS)){
        s[sPos] = tempS;
        if(s[sPos].length()>maxLen)
            maxLen = s[sPos].length();
        sPos++;
    }

    for(i=0; i<=maxLen+1; i++){
        cout << "*";
    }
    cout << '\n';

    ///Aquí ocurre la magia
    bool padelante;
    int remSpaces;
    bool padLeft = false;
    int stringIndex;
    int leftSpaces;
    int rightSpaces;
    for(i=0; i<sPos; i++){
        stringIndex = 0;
        padelante = true;
        remSpaces = maxLen - (s[i].length());
        leftSpaces = remSpaces/2;
        rightSpaces = remSpaces/2;
        remSpaces = remSpaces-(leftSpaces+rightSpaces);
        if(remSpaces>0 && padLeft){
            leftSpaces++;
            padLeft=false;
        }
        else if(remSpaces>0 && !padLeft){
            rightSpaces++;
            padLeft=true;
        }
        tempS = '*';
        for(j=0; j<maxLen; j++){
            if(leftSpaces>0){
                tempS += " ";
                leftSpaces--;
            }
            else if(stringIndex<s[i].length()){
                tempS += s[i][stringIndex++];
            }
            else tempS += " ";
        }
        tempS+='*';
        cout << tempS << '\n';
    }
    ///
    for(i=0; i<=maxLen+1; i++){
        cout << "*";
    }
    return 0;
}
