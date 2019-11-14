#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, i;
    int arr[100001];
    int arr2[100001];
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        arr2[i]=arr[i];
    }
    sort(arr2, arr2+n);
    int cont=0;
    for(i=0; i<n; i++){
        if(arr[i]!=arr2[i]){
            cont++;
        }
    }
    printf("%s\n", (cont<=2 ? "YES" : "NO"));
    return 0;
}