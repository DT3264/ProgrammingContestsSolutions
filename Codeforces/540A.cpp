#include<stdio.h>
int abs(int n){
    if(n<0) return n*-1;
    else return n;
}

int totalMovs(int n1, int n2){
    int movs = 10000000;
    if(abs(n2-n1-10)<movs) movs = abs(n2-n1-10);
    if(abs(n2-n1+10)<movs) movs = abs(n2-n1+10);
    if(abs(n2-n1)<movs) movs = abs(n2-n1);
    if(abs(n1-n2)<movs) movs = abs(n1-n2);
    return movs;
}

int main(){
    int i, n;
    long long total = 0;
    char arr1[1010], arr2[1010];
    scanf("%d %s %s", &n, arr1, arr2);
    for(i=0; i<n; i++){
       total += totalMovs(arr1[i]-'0', arr2[i]-'0');
    }
    printf("%lld\n", total);
    return 0;
}
