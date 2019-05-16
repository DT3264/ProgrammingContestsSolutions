#include<stdio.h>
int main(){
    long long n;
    while(scanf("%lld", &n) && n!=0){
        int iter=3;
        long long sum=19;
        long long toAdd=12;
        long long ans=15;
        while(iter!=n){
            ans+=sum;
            sum+=toAdd;
            toAdd+=3;
            iter++;
        }
		//linear
		//long long ans = n*((n*n)+1)/2;
        printf("%lld\n", ans);
    }
    return 0;
}
