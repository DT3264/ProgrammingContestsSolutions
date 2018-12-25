#include<stdio.h>
int hosts[100];
int guests[100];
int main(){
    int n, i, j, cont=0;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d%d", &hosts[i], &guests[i]);
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(hosts[i]==guests[j]){
                cont++;
            }
        }
    }
    printf("%d", cont);
    return 0;
}
