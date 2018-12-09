#include <iostream>

using namespace std;

string s, tempN;
int totPer;
int totPackages;
int i;

int main()
{
    while(getline(cin, s)){
        if(s[0]=='+')
            totPer++;
        else if(s[0]=='-')
            totPer--;
        else{
            for(i=0; s[i]!=':'; i++){
            }
            totPackages+=(s.length()-i-1)*totPer;
        }
    }
    cout << totPackages;
    return 0;
}
