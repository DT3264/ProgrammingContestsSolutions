#include <bits/stdc++.h>
using namespace std;
int tests[101];
int total;
void insertTest(int t){
    total+=t;
    tests[t]++;
}
int getMinN(int &m, int t){
    int actTotal=total+t;
    int res=0;
    for(int i=100; i>=1 && actTotal>m; i--){
        if(actTotal-(i*tests[i])>m){
            actTotal-=(i*tests[i]);
            res+=tests[i];
        }
        else{
            res+=ceil(((double)actTotal-(double)m)/(double)i);
            actTotal-=(i*tests[i]);
        }
    }
    return res;
}
int main(){
    int n, m, i, t;
    scanf("%d%d", &n, &m);
    int arr[101];
    int minN;
    for(i=0; i<n; i++){
        scanf("%d", &t);
        minN=getMinN(m, t);
        insertTest(t);
        printf("%d ", minN);
    }
    return 0;
}
