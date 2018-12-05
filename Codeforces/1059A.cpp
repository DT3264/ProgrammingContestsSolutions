#include<stdio.h>
int main(){
    int n, l, a;
    scanf("%d %d %d", &n, &l, &a);
    int tIni=0, contBreak=0;
    int t0, l0;
    for(int i=0; i<n; i++){
        scanf("%d %d", &t0, &l0);
        ///distancia desde tIni hasta t0 y ver cuantos descansos hay
        ///printf("distancia de %d a %d -> %d\n", tIni, t0, t0-tIni);
        contBreak += (t0-tIni)/a;
        tIni = t0 + l0;
    }
    ///printf("distancia de %d a %d -> %d\n", tIni, l, l-tIni);
    contBreak += (l-tIni)/a;
    printf("%d\n", contBreak);
    return 0;
}
