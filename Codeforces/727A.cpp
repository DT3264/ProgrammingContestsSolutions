#include<stdio.h>
int n, m;
int arr[100000];
bool found;
int totalNums;

void reachM(long long x, long long pos){
    if(x>m || found) return;
    if(x==m){
        arr[pos]=x;
        totalNums=pos+1;
        found=true;
        return;
    }
    arr[pos]=x;
    reachM((x*10)+1, pos+1);
    reachM(x*2, pos+1);
}

int main(){
    scanf("%d%d", &n, &m);
    reachM(n, 0);
    if(!found){
        printf("NO");
    }
    else{
        printf("YES\n");
        printf("%d\n", totalNums);
        for(int i=0; i<totalNums; i++){
            printf("%d ", arr[i]);
        }
    }
    return 0;
}
