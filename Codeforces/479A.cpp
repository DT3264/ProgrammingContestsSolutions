#include<stdio.h>
int main(){
    int a, b, c, maxN=0, i;
    int arr[6];
    scanf("%d %d %d", &a, &b, &c);
    arr[0]=a+b+c;
    arr[1]=a+(b*c);
    arr[2]=(a*b)+c;
    arr[3]=(a+b)*c;
    arr[4]=a*(b+c);
    arr[5]=a*b*c;
    for(i=0; i<6; i++){
        if(arr[i]>maxN) maxN=arr[i];
    }
    printf("%d\n", maxN);
    return 0;
}
