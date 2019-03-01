#include<stdio.h>
int n, i, j;
int actualStart;
long long maxP, actualP;
long long arr[20];
int contCases=1;
long long maxN(long long a, long long b){
    return (a>b ? a : b);
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d", &n)!=EOF){
        maxP=0;
        for(i=0; i<n; i++){
            scanf("%lld", &arr[i]);
            maxP=maxN(maxP, arr[i]);
        }
        for(i=2; i<=n; i++){
            actualStart=0;
            while(actualStart+i-1<n){
                actualP=arr[actualStart];
                for(j=actualStart+1; j<actualStart+i; j++){
                    actualP*=arr[j];
                }
                maxP=std::max(maxP, actualP);
                actualStart++;
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", contCases++, maxP);
    }
    return 0;
}
