#include<stdio.h>
int main(){
    int n, fN;
    scanf("%d", &n);
    fN=n;
    int pow1 = 1, pow2 = 1;
    int n1=0, n2=0;
    int contN = 1;
    bool isNegative = n<0;
    if(isNegative) n*=-1;
    while(n>0){
        ///printf("%d\n", n%10);
        if(contN==1){
            n1+=((n%10)*pow1);
            pow1*=10;
        }
        else if(contN==2){
            n2+=((n%10)*pow2);
            pow2*=10;
        }
        else{
            n1+=((n%10)*pow1);
            n2+=((n%10)*pow2);
            pow1*=10;
            pow2*=10;
        }
        n/=10;
        contN++;
    }
    if(isNegative){
        n1*=-1;
        n2*=-1;
    }
    ///printf("%d %d %d\n\n", n1, n2, fN);
    if(n1>=n2 && n1>=fN) printf("%d\n", n1);
    else if(n2>=n1 && n2>=fN) printf("%d\n", n2);
    else printf("%d\n", fN);
    return 0;
}
