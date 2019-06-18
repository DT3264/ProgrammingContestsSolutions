#include <bits/stdc++.h>
int main(){
    long long x, y, z;
    scanf("%lld%lld%lld", &x, &y, &z);
    long long totalC=0;
    long long minToGive=0;
    long long tx, ty, t1, t2;
    totalC+=(x/z)+(y/z);
    x%=z;
    y%=z;
    if(x+y>=z){
        tx=z-x;
        ty=z-y;
        totalC++;
        minToGive=std::min(tx, ty);
    }
    printf("%lld %lld", totalC, minToGive);
    return 0;
}
