#include<stdio.h>
int main (){
    int i, j;
    int answer;
    int months, drops;
    int actualMonth, prevMonth, nextMonth;
    double arrDrop[101];
    double monthPay, downPay, borrow, carValue, prevDrop, nextDrop;
    while(scanf("%d%lf%lf%d", &months, &downPay, &borrow, &drops) && months>0){
        scanf("%d%lf", &prevMonth, &prevDrop);
        for(i=0; i<drops-1; i++){
            scanf("%d%lf", &nextMonth, &nextDrop);
            for(j=prevMonth; j<nextMonth; j++){
                arrDrop[j]=prevDrop;
            }
            prevMonth=nextMonth;
            prevDrop=nextDrop;
        }
        for(i=prevMonth; i<101; i++){
            arrDrop[i]=prevDrop;
        }
        actualMonth=0;
        monthPay=borrow/months;
        carValue=(borrow+downPay)*(1-arrDrop[actualMonth++]);
        //printf("start at %d -> %f vs %f\n", actualMonth, carValue, borrow);
        while(carValue<=borrow){
            //printf("%d -> car: %f vs borrow: %f\n", actualMonth, carValue, borrow);
            carValue-=carValue*arrDrop[actualMonth++];
            borrow-=monthPay;
        }
        answer=actualMonth-1;
        printf("%d month", answer);
        if(answer!=1){
            printf("s");
        }
        printf("\n");
    }
    return 0;
}
