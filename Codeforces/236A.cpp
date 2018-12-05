#include <iostream>

using namespace std;

int arr[27], totalDif;
string s;

int main()
{
    cin >> s;
    int i, sLen = s.length();
    for(i=0; i<sLen; i++){
        arr[(int)s[i]-97]++;
    }
    for(i=0; i<27; i++) if(arr[i]>0) totalDif++;
    if(totalDif%2==0){
        cout << "CHAT WITH HER!";
    }
    else cout << "IGNORE HIM!";
    return 0;
}
