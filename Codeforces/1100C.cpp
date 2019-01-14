#include<stdio.h>
#include<math.h>
using namespace std;
float PI=acos(-1);
int main(){
    float n, r;
    float res;
    scanf("%f%f", &n, &r);
    res=(r*sin(PI/n))/(1-sin(PI/n));
    printf("%.7f", res);
    return 0;
}

