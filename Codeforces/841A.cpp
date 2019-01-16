#include<stdio.h>
#include<algorithm>
char str[101];
int n, k;
int main (){
    int i;
    scanf("%d%d", &n, &k);
    scanf("%s", str);
    std::sort(str, str+n);
    char actualChar=str[0];
    int cont=1;
    bool canBeMade=true;
    for(i=1; i<n && canBeMade; i++){
        if(str[i]==actualChar){
            cont++;
            if(cont>k){
                canBeMade=false;
            }
        }
        else{
            actualChar=str[i];
            cont=1;
        }
    }
    printf("%s", (canBeMade ? "YES" : "NO"));
    return 0;
}
