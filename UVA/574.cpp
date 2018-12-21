#include<stdio.h>
#include<string.h>
int t, n, arr[1001], contSums;
bool isUsed[1001];
int arrPermu[10000][12];
int actualPermu[12];
int permusUsed, actualPermuL;

bool existPermutation(){
    actualPermuL=0;
    memset(actualPermu, 0, sizeof(actualPermu));
    ///printf("actualPermu: \n");
    for(int i=0; i<n; i++){
        if(isUsed[i]){
            ///printf("%d ", arr[i]);
            actualPermu[actualPermuL++]=arr[i];
        }
    }
    ///printf(" -> \n*");
    for(int i=0; i<actualPermuL; i++){
       /// printf("%d ", actualPermu[i]);
    }
    ///printf("*\n");
    bool oneIsEqual=false;
    for(int i=0; i<permusUsed && !oneIsEqual; i++){
        bool isActualEqual=true;
        for(int j=0; j<actualPermuL; j++){
            if(arrPermu[i][j]!=actualPermu[j])isActualEqual=false;
        }
        if(isActualEqual) oneIsEqual=true;
    }
    return oneIsEqual;
}
void addPermutation(){
    ///printf("exist %d permus\n", permusUsed);
    memcpy(arrPermu[permusUsed++], actualPermu, sizeof(actualPermu));
    for(int i=0; i<actualPermuL; i++){
        printf("%d", actualPermu[i]);
        if(i<actualPermuL-1) printf("+");
    }
    printf("\n");
}

void suma(int actualN, int pos){
    if(pos>=n || actualN>t) return;
    if(actualN==t){
        if(!existPermutation()){
            addPermutation();
            contSums++;
        }
        return;
    }
    for(int i=pos+1; i<n; i++){
        isUsed[i]=true;
        suma(actualN+arr[i], i);
        isUsed[i]=false;
    }
}

int main (){
    int i;
    while(scanf("%d %d", &t, &n) && t!=0 && n!=0){
        permusUsed=0;
        contSums=0;
        for(i=0; i<n; i++){
            scanf("%d", &arr[i]);
        }
        printf("Sums of %d:\n", t);
        for(i=0; i<n; i++){
            isUsed[i]=true;
            suma(arr[i], i);
            isUsed[i]=false;
        }
        if(contSums==0) printf("NONE\n");
        ///else printf("%d sums\n", contSums);
    }
    return 0;
}
