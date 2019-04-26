#include<stdio.h>
#include<algorithm>
int main(){
    int n, m, i, t;
    int oddChests=0, evenChests=0;
    int oddKeys=0, evenKeys=0;
    scanf("%d%d", &n, &m);
    for(i=0; i<n; i++){
        scanf("%d", &t);
        if(t%2==0){
            oddChests++;
        }
        else{
            evenChests++;
        }
    }
    for(i=0; i<m; i++){
        scanf("%d", &t);
        if(t%2==0){
            oddKeys++;
        }
        else{
            evenKeys++;
        }
    }
    printf("%d", std::min(oddKeys, evenChests) + std::min(evenKeys, oddChests));
    return 0;
}
