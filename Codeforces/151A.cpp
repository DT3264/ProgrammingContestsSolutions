#include<stdio.h>
#include<math.h>
int main(){
    int n, k, l, c, d, p, nl, np;
    scanf("%d%d%d%d%d%d%d%d", &n, &k, &l, &c, &d, &p, &nl, &np);
    int totalMililliters=k*l;
    int totalSlices=d*c;
    int ans=0;
    while(totalMililliters>=nl && totalSlices>0 && p>=np){
        ans++;
        totalMililliters-=nl;
        totalSlices--;
        p-=np;
    }
    printf("%d", (int)round(ans/n));
}
