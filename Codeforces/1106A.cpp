#include<stdio.h>
int main (){
    int n;
    int i, j;
    int cont=0;
    char arr[502][502];
    scanf("%d", &n);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf(" %c", &arr[i][j]);
        }
    }
    for(i=0; i<n-2; i++){
        for(j=0; j<n-2; j++){
            if(arr[i][j]=='X' &&
               arr[i][j+2]=='X' &&
               arr[i+1][j+1]=='X' &&
               arr[i+2][j]=='X' &&
               arr[i+2][j+2]=='X'){
                cont++;
            }
        }
    }
    printf("%d", cont);
    return 0;
}
