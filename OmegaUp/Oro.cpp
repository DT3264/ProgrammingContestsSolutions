#include<stdio.h>

int arr[1000000];
int n, b;
long long minAfterMax=1e16;
void destroy(int oroActual, int pos){
    if(oroActual-b>=minAfterMax) return;
    if(oroActual>=b){
        if(minAfterMax>oroActual-b){
            minAfterMax=oroActual-b;
        }
        ///printf("%d %d\n", oroActual, oroActual-b);
    }
    if(pos>=n) return;
    ///Toma
    destroy(oroActual+arr[pos], pos+1);
    ///No toma
    destroy(oroActual, pos+1);
}

int main(){
    int i;
    scanf("%d%d", &n, &b);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    destroy(0, 0);
    printf("%lld", minAfterMax);
    return 0;
}
