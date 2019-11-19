    #include<bits/stdc++.h>
    using namespace std;
    int main(){
        int t;
        int x, y;
        bool can;
        scanf("%d", &t);
        while(t--){
            can=true;
            scanf("%d%d", &x, &y);
            if(x==1 && y>1){
                can=false;
            }
            if(x<=3 && y>3){
                can=false;
            }
            printf("%s\n", (can ? "Yes" : "No"));
        }
        return 0;
    }