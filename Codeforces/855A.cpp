#include<iostream>
#include<map>
using namespace std;
map<string, int> mapa;
int main(){
    int n, i;
    string str;
    cin >> n;
    for(i=0; i<n; i++){
        cin >> str;
        if(mapa[str]++==0){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
}
