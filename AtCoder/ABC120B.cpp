#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x, i, t, dist=0, cont=0;;
    scanf("%d%d", &n, &x);
    if(dist<=x){
        cont++;
    }
    for(i=0; i<n; i++){
        scanf("%d", &t);
        dist+=t;
        if(dist<=x){
            cont++;
        }
    }
    printf("%d\n", cont);
}
