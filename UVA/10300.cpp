#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
    int i, j;
    int cases;
    int farmers;
    int sizeFarm, animals, eFriendly;
    long long total;
    scanf("%d", &cases);
    for(i=0; i<cases; i++){
        scanf("%d", &farmers);
        total = 0;
        for(j=0; j<farmers; j++){
            scanf("%d %d %d", &sizeFarm, &animals, &eFriendly);
            total += (sizeFarm)*eFriendly;
        }
        printf("%d\n", total);
    }
    return 0;
}
