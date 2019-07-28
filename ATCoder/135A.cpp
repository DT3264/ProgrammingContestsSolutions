#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int a, b, k;
    scanf("%d%d", &a, &b);
    k=a+b;
    if(k%2!=0){
        printf("IMPOSSIBLE\n");
    }
    else{
        printf("%d\n", k/2);
    }
    return 0;
}
