#include<stdio.h>
int main(){
    int n, k, i;
    int y, kilo;
    double minKilos = 1000000000.0;
    double a;
    scanf("%d %d", &n, &k);
    for(i=0; i<n; i++){
        scanf("%d %d", &y, &kilo);
        a = ((double)y/(double)kilo)*k;
        if(a<minKilos) minKilos=a;
    }
    printf("%.8f\n", minKilos);
    return 0;
}
