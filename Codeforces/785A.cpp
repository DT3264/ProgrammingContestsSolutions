#include<stdio.h>
#include<string.h>
long long n, i, contSides;
char str[13];
int main(){
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%s", str);
        if(strcmp("Tetrahedron", str)==0) contSides+=4;
        if(strcmp("Cube", str)==0) contSides+=6;
        if(strcmp("Octahedron", str)==0) contSides+=8;
        if(strcmp("Dodecahedron", str)==0) contSides+=12;
        if(strcmp("Icosahedron", str)==0) contSides+=20;
    }
    printf("%lld", contSides);
    return 0;
}

