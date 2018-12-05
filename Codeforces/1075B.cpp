#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>

int usr[200002];///Array to keep pos data
int rider[100001];
long long taxi[100001];
int canTake[100001];///Every taxi how much can take
int actualRider=0;
int actualTaxi=0;

int n, m;

int main (){
    int i, j;
    scanf("%d %d", &n, &m);
    ///read the pos
    for(i=0; i<n+m; i++){
        scanf("%d", &usr[i]);
    }
    ///read if is taxi or not and order them
    int isT;
    for(i=0; i<n+m; i++){
        scanf("%d", &isT);
        ///is rider
        if(isT==0){
            rider[actualRider++]=usr[i];
        }
        ///is taxi
        else if(isT==1){
            taxi[actualTaxi++]=usr[i];
        }
    }
    taxi[actualTaxi++]=10000000001;
    for(i=0; i<=m; i++){
        ///printf("taxi %d -> %d\n", i, taxi[i]);
    }
    int indTaxi1=0, indTaxi2=1;
    long long dis1, dis2;
    for(j=0; j<n; j++){
        dis1 = abs(taxi[indTaxi1]-rider[j]);
        dis2 = abs(taxi[indTaxi2]-rider[j]);
        if(dis1<=dis2){
            canTake[indTaxi1]++;
        }
        else{
            ///Roll the rider before
            ///so the cicle keeps with the same rider but the indexes updated
            j--;
            indTaxi1++, indTaxi2++;
        }
    }
    for(i=0; i<m; i++){
        printf("%d ", canTake[i]);
    }
    return 0;
}
