#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int> primes;
bool used[4001];

void loadCrib(){
    for(int i=2; i<=4000; (i==2 ? i++ : i+=2)){
        if(!used[i]){
            primes.push_back(i);
            //printf("%d ", i);
            for(int j=i*i; j<=4000; j+=i){
                used[j]=true;
            }
        }
    }
}



int main(){
	int almostPrimes=0;
    loadCrib();
    int actualN, n, i;
    //printf("%d %d", 5%21, 21%5);
    scanf("%d", &n);
    for(int k=1; k<=n; k++){
        int contPrimes=0;
        int actualPrime=0;
        for(i=0; primes[i]<=k; i++){
            if(k%primes[i]==0){
                //printf("%d ", primes[i]);
                contPrimes++;
            }
        }
        if(contPrimes==2){
            //printf(" -> %d", k);
            almostPrimes++;
        }
        //printf("\n");
    }
    printf("%d", almostPrimes);
    return 0;
}
