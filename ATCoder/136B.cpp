#include<stdio.h>
#include<algorithm>
int main(){
    int n, ans=0;
    scanf("%d", &n);
    if(n>9999){
        n=std::min(n, 99999);
        ans+=(n - 9999);
    }
    if(n>99){
        n=std::min(n, 999);
        ans+=(n - 99);
    }
    if(n>=0){
        n=std::min(n, 9);
        ans+=n;
    }
    printf("%d\n", ans);
    return 0;
}
