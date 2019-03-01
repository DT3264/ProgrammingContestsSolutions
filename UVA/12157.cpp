#include<stdio.h>
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int cases, n, contCases=1;
    int totalJ, totalM;
    int actualN, tmpN;
    scanf("%d", &cases);
    while(cases--){
        totalJ=totalM=0;
        scanf("%d", &n);
        while(n--){
            scanf("%d", &actualN);
            tmpN=actualN;
            while(tmpN>=0){
                tmpN-=30;
                totalM+=10;
            }
            tmpN=actualN;
            while(tmpN>=0){
                tmpN-=60;
                totalJ+=15;
            }
        }
        printf("Case %d:", contCases++);
        if(totalM<=totalJ){
            printf(" Mile");
        }
        if(totalJ<=totalM){
            printf(" Juice");
        }
        printf(" %d\n", (totalM<=totalJ ? totalM : totalJ));
    }
    return 0;
}
