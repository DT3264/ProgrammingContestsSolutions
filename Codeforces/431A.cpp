#include<stdio.h>
#include<string.h>
int arr[4];
int main(){
    int i, total=0;
    for(i=0; i<4; i++){
        scanf("%d", &arr[i]);
    }
    char str[100001];
    scanf("%s", str);
    int strLen = strlen(str);
    for(i=0; i<strLen; i++){
        total+=arr[str[i]-'1'];
    }
    printf("%d", total);
    return 0;
}
