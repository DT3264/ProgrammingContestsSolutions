#include<stdio.h>
using namespace std;

int main(){
    int a=0, b=0, n, t, i;
    scanf("%d", &t);
    a+=t;
    scanf("%d", &t);
    a+=t;
    scanf("%d", &t);
    a+=t;
    scanf("%d", &t);
    b+=t;
    scanf("%d", &t);
    b+=t;
    scanf("%d", &t);
    b+=t;
    scanf("%d", &n);
    while(a>0){
        a-=5;
        n--;
    }
    while(b>0){
        b-=10;
        n--;
    }
    printf(n>=0 ? "YES" : "NO");
    return 0;
}
