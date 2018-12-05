#include<stdio.h>
#include<algorithm>
int arr[400001];
int elPos[200000];
int posLeft = 200000;
int posRight = 200001;
int n, m;

void addToLeft(int n){
    arr[posLeft--]=n;
    elPos[n]=posLeft+1;
}

void addToRight(int n){
    arr[posRight++]=n;
    elPos[n]=posRight-1;
}

int touchBorder(int n){
    int i;
    ///for(i=posLeft+1; i<posRight && arr[i]!=n; i++);
    ///printf("%d is at %d with distance of -> %d and <- %d \n", n, i+1, i-posLeft-1, posRight-i-1);
    ///printf("arr[%d] at pos %d\n", n, elPos[n]-posLeft);
    i=elPos[n];
    int l = i-posLeft-1, r = posRight-i-1;
    return l<=r ? l : r;
}

int main(){
    int i;
    char op;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf(" %c %d", &op, &m);
        if(op=='L'){
            addToLeft(m);
        }
        else if(op=='R'){
            addToRight(m);
        }
        else if(op=='?'){
            printf("%d\n", touchBorder(m));
        }
        /*for(int j=posLeft+1; j<posRight; j++){
            printf("%d ", arr[j]);
        }
        printf("\n");*/
    }
}
