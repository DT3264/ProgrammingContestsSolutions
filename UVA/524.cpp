#include<stdio.h>
#include<string.h>
int n;
int arr[16];
bool used[20];
bool criba[100];

void loadSieve(){
    int i, j;
    criba[0]=true;
    criba[1]=true;
    for(i=2; i<=99; (i==2 ? i++ : i+=2)){
        if(!criba[i]){
            for(j=i*i; j<=99; j+=i){
                criba[j]=true;
            }
        }
    }
}

bool isPrime(int x){
    return !criba[x];
}

void primeRing(int pos){
    int actualN=arr[pos];
    if(pos==n-1){
        if(isPrime(actualN+1)){
            for(int i=0; i<n; i++){
                printf("%d", arr[i]);
                if(i<n-1){
                    printf(" ");
                }
            }
            printf("\n");
        }
        return;
    }
    for(int i=2; i<=n; i++){
        if(!used[i] && isPrime(actualN+i)){
            used[i]=true;
            arr[pos+1]=i;
            primeRing(pos+1);
            used[i]=false;
        }
    }
}

int main(){
    loadSieve();
    int contCases=1;
    while(scanf("%d", &n)!=EOF){
        if(contCases>1){
            printf("\n");
        }
        printf("Case %d:\n", contCases++);
        used[1]=true;
        arr[0]=1;
        primeRing(0);
        memset(used, 0, sizeof(used));
    }
    return 0;
}
