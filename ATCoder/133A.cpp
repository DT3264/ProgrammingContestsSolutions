#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    n*=a;
    int ans=min(n, b);
    printf("%d\n", ans);
    return 0;
}
