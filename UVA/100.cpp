#include<stdio.h>
#include<algorithm>
int arr[1000001];
int sequenceOf(long long b){
    int cont=1;
    while(b!=1){
        if(b%2!=0){
            b=(3*b)+1;
        }
        else{
            b/=2;
        }
        cont++;
    }
    return cont;
}

int main (){
    int a, b, i, t, res;
    bool switched;
    for(i=1; i<=1000000; i++){
        arr[i]=sequenceOf(i);
    }
    while(scanf("%d%d", &a, &b)!=EOF){
        switched=false;
        if(a>b){
            std::swap(a, b);
            switched=true;
        }
        res=-1;
        for(i=a; i<=b; i++){
            res=std::max(res, arr[i]);
        }
        if(switched){
            std::swap(a, b);
        }
        printf("%d %d %d\n", a, b, res);
    }
    return 0;
}
