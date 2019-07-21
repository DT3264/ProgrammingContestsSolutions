#include<stdio.h>
#include<math.h>
int main(){
    int n, d;
    scanf("%d%d", &n, &d);
    int sum=0, inspect=0;
    while(sum<n){
        sum+=(2*d)+1;
        inspect++;
    }
    printf("%d\n", inspect);
    return 0;
}
