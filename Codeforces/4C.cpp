#include<stdio.h>
#include<map>
#include<string>
using namespace std;


map<string, int> mapa;
int main(){
    string str;
    char strC[32];
    int i, n;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%s", strC);
        str = strC;
        mapa[str]++;
        if(mapa[str]>1) printf("%s%d\n", strC, mapa[str]-1);
        else printf("OK\n");
    }
    return 0;
}
