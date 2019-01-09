#include<stdio.h>
int n, d;
int arr[200];
int reached=-1;
bool alreadySteped[110];
void jump(int actualPos, int jumps){
    if(alreadySteped[actualPos] || reached!=-1){
        return;
    }
    if(actualPos==n-1){
        reached=jumps;
        return;
    }
    alreadySteped[actualPos]=true;
    for(int i=d+actualPos; i>actualPos; i--){
        if(arr[i]==1){
            jump(i, jumps+1);
        }
    }
}

int main(){
    int i;
    scanf("%d%d", &n, &d);
    for(i=0; i<n; i++){
        scanf(" %c", &arr[i]);
        arr[i]-='0';
    }
    jump(0, 0);
    printf("%d", reached);
    return 0;
}
