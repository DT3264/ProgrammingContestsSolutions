#include<stdio.h>
#include<string.h>

struct persona{
    int initialMoney;
    int finalMoney;
    char nombre[120];
};

int main(){
    int i, j, k, n;
    char actualPerson[120];
    int actualMoney;
    int personsToGift;
    char personToGift[120];
    persona personas[100];
    bool alreadyReaded=false;
    while(scanf("%d", &n)!=EOF){
        if(alreadyReaded) printf("\n");
        for(i=0; i<n; i++){
            scanf("%s", personas[i].nombre);
            personas[i].initialMoney = 0;
            personas[i].finalMoney = 0;
        }
        for(i=0; i<n; i++){
            scanf("%s %d %d", actualPerson, &actualMoney, &personsToGift);
            for(j=0; j<n && strcmp(actualPerson, personas[j].nombre)!=0; j++);
            int moneyToEach = 0;
            int moneyRemaining = 0;
            if(personsToGift!=0){
                moneyToEach = actualMoney/personsToGift;
                moneyRemaining = actualMoney-(actualMoney/personsToGift)*personsToGift;
                ///printf("%d / %d = %d y queda %d\n", actualMoney, personsToGift, moneyToEach, moneyRemaining);
                personas[j].initialMoney = actualMoney;
                personas[j].finalMoney += moneyRemaining;
                for(j=0; j<personsToGift; j++){
                    scanf("%s", personToGift);
                    for(k=0; k<n && strcmp(personas[k].nombre, personToGift)!=0; k++);
                    ///printf("%s == %s\n", personToGift, personas[k].nombre);
                    personas[k].finalMoney+=moneyToEach;
                }
            }
        }
        for(i=0; i<n; i++){
            printf("%s %d\n", personas[i].nombre, personas[i].finalMoney-personas[i].initialMoney);
        }
        alreadyReaded = true;
    }
    return 0;
}
