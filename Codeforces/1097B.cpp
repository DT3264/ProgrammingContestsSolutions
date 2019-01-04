#include<stdio.h>
int n;
int arr[15];
bool found;

void rotateLock(int x, int pos){
    x=x%360;
    if(found){
        return;
    }
    if(pos==n){
        if(x==0){
            found=true;
        }
        return;
    }
    rotateLock(x+arr[pos], pos+1);
    rotateLock(x-arr[pos], pos+1);
}

int main(){
    int i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    rotateLock(arr[0], 1);
    rotateLock(-arr[0], 1);
    printf("%s\n", (found ? "YES" : "NO"));
}