#include<stdio.h>
int main(){
    int t, i;
    long long n, k;
    scanf("%d", &t);
    for(i=0; i<t; i++){
        scanf("%lld%lld", &n, &k);
        long long cont=0;
        while(n!=0){
            if(n%k==0){
                n/=k;
                cont++;
            }
            else{
                cont+=n%k;
                n-=n%k;
            }
        }
        printf("%lld\n", cont);
    }
    return 0;
}
