#include<stdio.h>
#include<algorithm>
struct site{
char url[101];
int val;
}sites[10];
int main(){
    int n, cases, contCases=1, i;
    int maxVal;
    scanf("%d", &cases);
    while(cases--){
        printf("Case #%d:\n", contCases++);
        int maxVal=0;
        for(i=0; i<10; i++){
            scanf("%s %d", sites[i].url, &sites[i].val);
            maxVal=std::max(maxVal, sites[i].val);
        }
        for(i=0; i<10; i++){
            if(sites[i].val==maxVal){
                printf("%s\n", sites[i].url);
            }
        }
    }
    return 0;
}
