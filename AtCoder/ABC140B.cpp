#include <bits/stdc++.h>
using namespace std;
int a[21], b[21], c[21];
int main(){
    int n, i;
    int total=0;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for(i=0; i<n; i++){
        scanf("%d", &b[i]);
    }
    for(i=0; i<n-1; i++){
        scanf("%d", &c[i]);
    }
    total+=b[a[0]-1];
    for(i=1; i<n; i++){
        total+=b[a[i]-1];
        if(a[i-1]+1==a[i]){
            total+=c[a[i-1]-1];
        }
    }

    printf("%d", total);
}
