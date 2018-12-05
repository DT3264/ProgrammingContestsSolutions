#include<stdio.h>
bool criba[1000000];
int primeNumbers[60000], cantPrimes=0;
int matrix[501][501];
long long minCost = 1000000;
long long total;

void loadPrimes(){
    int i, j;
    primeNumbers[cantPrimes++]=2;
    for(i=2; i<200000; i+=2){
        for(j=i+i; j<200000; j+=i){
            criba[j]=true;
        }
    }
    for(i=3; i<200000; i+=2){
        if(!criba[i]){
            primeNumbers[cantPrimes++]=i;
            for(j=i+i; j<200000; j+=i){
                criba[j]=true;
            }
        }
    }
}

int findNextPrime(int n){
    int left=0, right=cantPrimes, mid;
    while(left!=right){
        mid = ((left+right)/2);
        if(primeNumbers[mid]<n){
            left=mid+1;
        }
        else if(primeNumbers[mid]>n){
            right=mid;
        }
        else if(primeNumbers[mid]==n) return primeNumbers[mid];
    }
    if(primeNumbers[mid]<n) mid++;
    ///printf("%d == %d\n", mid, primeNumbers[mid]);
    return primeNumbers[mid];
}

int main (){
    int i, j, n, m;
    loadPrimes();
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    for(i=0; i<n; i++){
        total=0;
        for(j=0; j<m; j++){
            ///printf("%d-%d\t", matrix[i][j], findNextPrime(matrix[i][j]));
            total+=findNextPrime(matrix[i][j])-matrix[i][j];
        }
        ///printf(" -> %d\n", total);
        if(total<minCost)minCost=total;
    }
    for(i=0; i<m; i++){
        total=0;
        for(j=0; j<n; j++){
            ///printf("%d-%d\t", matrix[j][i], findNextPrime(matrix[j][i]));
            total+=findNextPrime(matrix[j][i])-matrix[j][i];
        }
        ///printf(" -> %d\n", total);
        if(total<minCost)minCost=total;
    }
    printf("%lld\n", minCost);
    return 0;
}
