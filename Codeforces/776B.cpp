#include<stdio.h>
bool used[100002];
int lastPrimePos;

void criba(){
    for(long long i=2; i<=100001; (i==2 ? i+=1 : i+=2)){
        if(!used[i]){
            for(long long j=i*i; j<=100001; j+=i){
                used[j]=true;
            }
        }
    }
}
int pieces[100003];
int main(){
    int n, i, j;
    criba();
    scanf("%d", &n);
    int colorCount=1;
    int maxColor=0;
    for(i=2; i<=n+1; i++){
        if(!used[i]){
            pieces[i]=1;
        }
        else{
            pieces[i]=2;
        }
        if(pieces[i]>maxColor){
            maxColor=pieces[i];
        }
    }
    printf("%d\n", maxColor);
    for(i=2; i<=n+1; i++){
        printf("%d ", pieces[i]);
    }
    return 0;
}
