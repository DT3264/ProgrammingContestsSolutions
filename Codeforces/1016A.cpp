#include<stdio.h>

int pagesTurned(int &actualNames, int namesToday, int namesPerDay){
    actualNames+=namesToday;
    int pagesTurned = actualNames/namesPerDay;
    actualNames -= (actualNames/namesPerDay)*namesPerDay;
    return pagesTurned;
}

int main(){
    int i;
    int days, namesPerDay, namesToday, actualNames=0;
    scanf("%d %d", &days, &namesPerDay);
    for(i=0; i<days; i++){
        scanf("%d", &namesToday);
        printf("%d ", pagesTurned(actualNames, namesToday, namesPerDay));
    }
    printf("\n");
    return 0;
}
