#include<stdio.h>
using namespace std;

int main(){
    int n, i, t1, t2, j, maxN;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &t1);
        maxN=0;
        for(j=0; j<t1; j++){
            scanf("%d", &t2);
            if(t2>maxN) maxN=t2;
        }
        printf("Case %d: %d\n", i+1, maxN);
    }
    return 0;
}
