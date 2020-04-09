#include<bits/stdc++.h>
using namespace std;
struct S{
    string o;
    string n;
};
map<string, int> mapa;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<S> vec;
    string s;
    S str;
    while(cin >> s && s!="#"){
        str.o=s;
        for(char &c : s){
            if(c>='A' && c<='Z'){
                c+=32;
            }
        }
        sort(s.begin(), s.end());
        mapa[s]++;
        str.n=s;
        vec.push_back(str);
    }
    sort(vec.begin(), vec.end(), [](const S &s1, const S &s2){
        return s1.o < s2.o;
    });
    for(S s : vec){
        if(mapa[s.n]==1)
        cout << s.o << "\n";
    }
	return 0;
}