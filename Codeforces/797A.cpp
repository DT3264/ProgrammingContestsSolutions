#include<stdio.h>
#include<vector>
using namespace std;
vector<int> primes;
bool used[1000001];

int arr[1000];
int contAns;

void criba(){
    for(int i=2; i<=1000000; (i==2 ? i++ : i+=2)){
        if(!used[i]){
            primes.push_back(i);
            for(int j=i*i; j<=1000000; j+=i){
                used[i]=1;
            }
        }
    }
}

int main(){
    criba();
    int i;
    int n, m;
    scanf("%d%d", &n, &m);
    for(i=0; primes[i]*primes[i]<=n; i++){
        while(n%primes[i]==0){
            arr[contAns++]=primes[i];
            n/=primes[i];
        }
    }
    if(n!=1) arr[contAns++]=n;
    while(contAns>m){
        arr[contAns-2]*=arr[contAns-1];
        contAns--;
    }
    if(contAns==m){
        for(i=0; i<contAns; i++){
            printf("%d ", arr[i]);
        }
    }
    else printf("-1");
    return 0;
}