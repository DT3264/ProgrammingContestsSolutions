#include<iostream>
#include<map>
using namespace std;
string persons[2000000];
map<string, int> mapa;

int main(){
    std::ios::sync_with_stdio(false);
    int n, i;
    cin >> n;
    for(i=0; i<n; i++){
        cin >> persons[i];
    }
    for(i=n-1; i>=0; i--){
        if(mapa[persons[i]]==1){
            continue;
        }
        else{
            cout << persons[i] << '\n';
            mapa[persons[i]]++;
        }
    }
    return 0;
}
