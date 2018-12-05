#include<stdio.h>
bool shoes[100001];
int main(){
    int n;
    int i, t, maxShoes=0, contShoes=0;
    scanf("%d", &n);
    for(i=0; i<n*2; i++){
        scanf("%d", &t);
        shoes[t-1]=!shoes[t-1];
        if(shoes[t-1]) contShoes++;
        else contShoes--;
        if(contShoes>maxShoes) maxShoes=contShoes;
    }
    printf("%d\n", maxShoes);
    return 0;
}
