#include <bits/stdc++.h>
using namespace std;
int MAX=(1e6)+1;
struct group{
    char character;
    int times;
};

void fillVector(vector<group> &v, char *str){
    int strLen=strlen(str);
    int vPos=0;
    int i;
    v.push_back({str[0], 1});
    for(i=1; i<strLen; i++){
        if(v[vPos].character==str[i]){
            v[vPos].times++;
        }
        else{
            vPos++;
            v.push_back({str[i], 1});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, i;
    scanf("%d", &n);
    while(n--){
        vector<group> v1, v2;
        char str1[MAX], str2[MAX];
        scanf("%s", str1);
        scanf("%s", str2);
        fillVector(v1, str1);
        fillVector(v2, str2);
        bool isValid=true;
        if(v2.size()!=v1.size()){
            isValid=false;
        }
        else{
            for(i=0; i<v1.size() && isValid; i++){
                if(v1[i].character==v2[i].character){
                    if(v1[i].times>v2[i].times){
                        isValid=false;
                    }
                }
                else{
                    isValid=false;
                }
            }
        }
        cout << (isValid ? "YES" : "NO") << "\n";
    }
    return 0;
}
