#include<iostream>
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cases;
    int n, m;
    int ans;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d%d", &n, &m);
        while(n%3!=0){
            n--;
        }
        while(m%3!=0){
            m--;
        }
        ans=(n*m)/9;
        printf("%d\n", ans);
    }
    return 0;
}

