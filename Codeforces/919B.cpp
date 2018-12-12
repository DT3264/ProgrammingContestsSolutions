#include<stdio.h>
#include<windows.h>
int n;
int actualSum;
int kEsim=0;
int arr[10];
void addN(int pos){
    actualSum-=arr[pos];
    arr[pos]++;
    if(arr[pos]==10) arr[pos]=0;
    actualSum+=arr[pos];
    if(arr[pos]==0) addN(pos-1);
}

int main(){
    int i=0;
    scanf("%d", &n);
    while(kEsim!=n){
        addN(9);
        if(actualSum==10){
            kEsim++;
        }
    }
    for(i=0; arr[i]==0; i++);
    for(i=i; i<10; i++){
        printf("%d", arr[i]);
    }
    return 0;
}
