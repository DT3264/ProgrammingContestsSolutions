#include<algorithm>
#include<stdio.h>
#include<math.h>
long long n, k, i;
long long divisores[10000000];
int contDiv;
int main(){
    scanf("%lld%lld", &n, &k);
    int sqrN = sqrt(n);
    for(i=1; i<=sqrN; i++){
        if(n%i==0){
            divisores[contDiv++]=i;
            if((n/i)!=i){
                divisores[contDiv++]=n/i;
            }
        }
    }
    std::sort(divisores, divisores+contDiv);
    if(k<=contDiv){
        printf("%lld", divisores[k-1]);
    }
    else{
        printf("-1");
    }
    return 0;
}
