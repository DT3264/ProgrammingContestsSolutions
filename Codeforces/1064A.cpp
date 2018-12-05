#include<stdio.h>

int minN = 1e9;
bool found = false;
void triangle(int a, int b, int c, int pos){
    if(found)return;
    if(a+b>c && a+c>b && b+c>a){
        ///printf("%d\n", pos);
        if(minN>pos) minN=pos;
        found = true;
        return;
    }
    if(a<=b && a<=c)
        triangle(a+1, b, c, pos+1);
    if(b<=a && b<=c)
        triangle(a, b+1, c, pos+1);
    if(c<=a && c<=b)
    triangle(a, b, c+1, pos+1);
}

int main (){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    triangle(a, b, c, 0);
    printf("%d", minN);
    return 0;
}
