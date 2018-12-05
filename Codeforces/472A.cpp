#include<stdio.h>
using namespace std;

bool crib[1000000];

void loadCrib(){
    int i, j;
    for(i=2; i<1000000; i++){
        for(j=i+i; j<1000000; j+=i){
            crib[j]=true;
        }
    }
}

int main(){
    int n, i, j;
    scanf("%d", &n);
    loadCrib();
    for(i=4; i<n; i++){
        if(crib[i]){
            for(j=5; j<n; j++){
                if(crib[j]){
                    if(i+j==n){
                        printf("%d %d\n", i, j);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
