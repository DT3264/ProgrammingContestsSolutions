#include <iostream>
#include <math.h>

using namespace std;

bool criba[10000001];
int cantTPrimes;
long long i, j;

int n;
bool isPPrime;
long long t;
long long sqrtT;

void loadCrib(){
    criba[0]= true;
    criba[1]=true;
    for(i=2; i<10000001; i++){
        if(!criba[i]){
            //arrTPrimes[cantTPrimes++] = i*i;
            for(j=i*i; j<10000001; j+=i){
                criba[j]=true;
            }
        }
    }
}

int main(){
    loadCrib();
    cin >> n;
    for(i=0; i<n; i++){
        cin >> t;
        isPPrime = false;
        sqrtT = (long long)sqrt(t);
        if(t == sqrtT*sqrtT){
            if(!criba[sqrtT]) isPPrime = true;
        }
        cout << (isPPrime ? "YES" : "NO") << "\n";
    }
    return 0;
}
