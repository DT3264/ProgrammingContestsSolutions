#include<stdio.h>
int main (){
    int n;
    int arr[5] = {100, 20, 10, 5, 1};
    scanf("%d", &n);
    int total=0;
    int i;
    for(i=0; i<5; i++){
        ///printf("%d of %d and left %d\n", n/arr[i], arr[i], n%arr[i]);
        total+=n/arr[i];
        n=n%arr[i];
    }
    printf("%d", total);
    return 0;
}
