#include<stdio.h>
int x, y, z, t1, t2, t3;
int costElevator, costStairs;
int main(){
    scanf("%d%d%d%d%d%d", &x, &y, &z, &t1, &t2, &t3);
    ///The elevator gets to Masha's floor
    while(z>x){
        z--;
        costElevator+=t2;
    }
    while(z<x){
        z++;
        costElevator+=t2;
    }
    ///Now the elevator opens and closes
    costElevator+=t3*2;
    ///The elevator gets to Egor's floor
    while(z>y){
        z--;
        costElevator+=t2;
    }
    while(z<y){
        z++;
        costElevator+=t2;
    }
    ///Now the elevator opens
    costElevator+=t3;
    ///Masha walks to Egor's floor
    while(x>y){
        x--;
        costStairs+=t1;
    }
    while(x<y){
        x++;
        costStairs+=t1;
    }
    printf("%s", (costElevator<=costStairs ? "YES" : "NO"));
}
