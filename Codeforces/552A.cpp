#include<stdio.h>
using namespace std;

int arr[101][101];
long long total = 0;

int main(){
    int n, i, j, k;
    int x1, y1, x2, y2;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for(j=x1; j<=x2; j++){
            for(k=y1; k<=y2; k++){
                arr[j][k]++;
            }
        }
    }
    for(i=1; i<=100; i++){
        for(j=1; j<=100; j++){
            total += arr[i][j];
        }
    }
    printf("%lld\n", total);
    return 0;
}
