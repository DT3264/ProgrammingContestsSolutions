#include<stdio.h>
#include<algorithm>
int main(){
    int n, m;
    int ans;
    int n1, n2;
    while(scanf("%d%d", &n, &m) && (n!=-1 && m!=-1)){
        n1=n, n2=n;
        ans=0;
        while(n1!=m && n2!=m){
            n1--;
            n2++;
            ans++;
            if(n1<0){
                n1=99;
            }
            if(n2>99){
                n2=0;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
