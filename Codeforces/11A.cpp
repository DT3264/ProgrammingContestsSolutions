#include<stdio.h>
int arr[1000000];
int main(){
    int n, m, i, contMovs=0;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(i=0; i<n-1; i++){
        if(arr[i]>=arr[i+1]){
            ///printf("%d - %d -> %d\n", arr[i], arr[i+1], ((arr[i]-arr[i+1])/m)+1);
            contMovs+=((arr[i]-arr[i+1])/m)+1;
            arr[i+1]+=(((arr[i]-arr[i+1])/m)+1)*m;

        }
    }
    printf("%d", contMovs);
    return 0;

}
