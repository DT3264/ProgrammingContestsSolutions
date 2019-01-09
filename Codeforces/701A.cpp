#include<stdio.h>
int n, searching;
int arr[100];
bool used[100];

void mark(int j, int k){
    printf("%d %d\n", j+1, k+1);
    used[j]=true;
    used[k]=true;
}

int main(){
    int i, j, k;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        searching+=arr[i];
    }
    searching/=(n/2);
    for(i=0; i<n; i++){
        if(!used[i]){
            for(j=i+1; j<n; j++){
                if(!used[j]){
                    if(arr[i]+arr[j]==searching){
                        mark(i, j);
                        i=0;
                        j=n;
                    }
                }
            }
        }
    }
    return 0;
}
