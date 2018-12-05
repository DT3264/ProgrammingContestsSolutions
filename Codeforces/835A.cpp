#include<stdio.h>
int main (){
    int s, v1, v2, t1, t2;
    scanf("%d%d%d%d%d", &s, &v1, &v2, &t1, &t2);
    int res1 = (t1*2)+(s*v1);
    int res2 = (t2*2)+(s*v2);
    if(res1<res2) printf("First");
    else if(res1>res2) printf("Second");
    if(res1==res2) printf("Friendship");
    return 0;
}
