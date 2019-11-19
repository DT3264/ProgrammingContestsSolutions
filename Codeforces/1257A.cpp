    #include<bits/stdc++.h>
    using namespace std;
    int main(){
        int t;
        int n, x;
        int a, b, ta, tb;
        scanf("%d", &t);
        while(t--){
            scanf("%d%d%d%d", &n, &x, &a, &b);
            if(a>b){
                int tmp=a;
                a=b;
                b=tmp;
            }
            ta=a;
            tb=b;
            ta-=x;
            if(ta<1){
                ta=1;
            }
            x-=(a-ta);
            tb+=x;
            if(tb>n){
                tb=n;
            }
            printf("%d\n", tb-ta);
        }
        return 0;
    }