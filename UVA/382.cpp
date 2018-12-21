#include<stdio.h>
#include<math.h>
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    long long a;
    long long total, i;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%lld", &a) && a!=0){
        total = 0;
        for(i=1; i<=a/2; i++){
            if(a%i==0) total+=i;
            //printf("%lld mod %lld == %lld\n", a, i, a%i);
        }
        cout << setw(5) << a;
        //printf("%lld  ", a);
        if(total==a) printf("  PERFECT\n");
        else if(total>a) printf("  ABUNDANT\n");
        else if(total<a) printf("  DEFICIENT\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
