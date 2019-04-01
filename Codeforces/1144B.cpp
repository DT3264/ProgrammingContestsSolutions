#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int arrOdd[2010], arrEven[2010];
int sizeOdd, sizeEven;
int n;
int main(){
    int n, i;
    scanf("%d", &n);
    int t;
    for(i=0; i<n; i++){
        scanf("%d", &t);
        if(t%2==0){
            arrEven[sizeEven++]=t;
        }
        else{
            arrOdd[sizeOdd++]=t;
        }
    }
    std::sort(arrOdd, arrOdd+sizeOdd);
    std::sort(arrEven, arrEven+sizeEven);
    int rem=min(sizeEven, sizeOdd);
    int ans=0;
    if(rem<sizeEven){
        for(i=0; i<sizeEven-rem-1; i++){
            ans+=arrEven[i];
        }
    }
    else if(rem<sizeOdd){
        for(i=0; i<sizeOdd-rem-1; i++){
            ans+=arrOdd[i];
        }
    }
    printf("%d", ans);
}