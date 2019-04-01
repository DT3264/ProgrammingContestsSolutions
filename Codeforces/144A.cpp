#include<stdio.h>
#include<string.h>
#include<algorithm>

bool solve(){
    char str[110];
    bool rep[28];
    bool ans=true;
    scanf("%s", str);
    int strLen=strlen(str);
    std::sort(str, str+strLen);
    for(int i=0; i<strLen-1; i++){
        if(str[i]!=str[i+1]-1){
            ans=false;
        }
        rep['a'-str[i]]++;
        if(rep['a'-str[i]]>1){
            ans=false;
        }
    }
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        printf("%s\n", (solve() ? "Yes" : "No"));
    }
}