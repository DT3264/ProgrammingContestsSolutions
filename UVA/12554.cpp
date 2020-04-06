#include <bits/stdc++.h>
using namespace std;
vector<string> song={"Happy","birthday","to","you","Happy","birthday","to","you","Happy","birthday","to","Rujia","Happy","birthday","to","you"};
vector<string> names;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    names.resize(n);
    int songPos=0;
    int namePos=0;
    for(string &s : names){
        cin >> s;
    }
    bool vuelta=false;
    while(true){
        cout << names[namePos] << ": " << song[songPos] << "\n";
        namePos++;
        songPos++;
        if(songPos==song.size() && vuelta){
            break;
        }
        if(namePos==names.size()){
            namePos=0;
            vuelta=true;
        }
        if(songPos==song.size()){
            songPos=0;
        }
    }
    return 0;
}
