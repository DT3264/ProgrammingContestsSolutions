#include<stdio.h>
using namespace std;
int main(){
    long long n;
    int q, i, j;
    long long x, y;
    long long nfp, nfi, nefp, nefi, vcpp;
    scanf("%lld %d", &n, &q);
    for(i=0; i<q; i++){
        scanf("%lld %lld", &x, &y);
        nfp = (x-1)/2;
        nfi = x/2;
        nefp = n/2;
        nefi = (n+1)/2;
        vcpp = (nfp * nefp) + (nfi * nefi) + ((y-1)/2)+1;
        if(!(x%2==0 && y%2==0) && !(x%2!=0 & y%2!=0)){
            vcpp += (n%2==0 ? (n*n)/2 : ((n*n)/2)+1);
            if(n%2!=0 && x%2==0 && y==1)vcpp--;
            else if(n%2!=0 && x%2!=1 && y!=1)
                vcpp--;
        }
        printf("%lld", vcpp);
        printf(i<q-1 ? "\n" : "");
    }
    return 0;
}
