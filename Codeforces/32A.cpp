#include<stdio.h>
int arr[1001];
int n, m, cont, t;
void swapN(int &a, int &b){
    t=a;
    a=b;
    b=t;
}

void check(int a, int b){
    if(a>b){
        swapN(a, b);
    }
    if(b-a<=m){
        cont++;
    }
}

int main (){
    int i, j;
    scanf("%d%d", &n, &m);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i==j){
                continue;
            }
            check(arr[i], arr[j]);
        }
    }
    printf("%d", cont);
    return 0;
}
