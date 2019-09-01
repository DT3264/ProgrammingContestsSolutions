#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, d;
    int i, j, k;
    int arr[11][11];
    scanf("%d%d", &n, &d);
    for(i=0; i<n; i++){
        for(j=0; j<d; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int ans=0;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            int sum=0;
            for(k=0; k<d; k++){
                sum+=pow(abs(arr[i][k]-arr[j][k]), 2);
            }
            double testVal=sqrt(sum);
            //printf("%d and %d: %d\n", i, j, sum);
            if(testVal-(int)testVal==0.000){
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
