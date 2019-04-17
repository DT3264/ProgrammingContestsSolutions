#include<stdio.h>
#include<algorithm>
int food[3];
int tFood[3];
bool has;
void bUpFood(){
    for(int i=0; i<3; i++){
        tFood[i]=food[i];
    }
}
void restoreFood(){
    has=true;
    for(int i=0; i<3; i++){
        food[i]=tFood[i];
    }
}
bool removeIfNo0(int n){
    if(food[n]!=0 && has){
        food[n]--;
        return true;
    }
    has=false;
    return false;
}
int main(){
    int i;
    for(i=0; i<3; i++){
        scanf("%d", &food[i]);
    }
    int atMostNWeeks=food[0]/3;
    for(i=1; i<3; i++){
        atMostNWeeks=std::min(atMostNWeeks, food[i]/2);
    }
    int eaten[3];
    eaten[0]=atMostNWeeks*3;
    eaten[1]=atMostNWeeks*2;
    eaten[2]=atMostNWeeks*2;
    for(i=0; i<3; i++){
        food[i]-=eaten[i];
    }
    int ans=eaten[0]+eaten[1]+eaten[2];
    int t1=0;
    int t2=0;
    bUpFood();
    ///Simulate the last week
        int tMax=0;
        has=true;
        ///L
        if(removeIfNo0(0)) t1++;
        if(removeIfNo0(1)) t1++;
        if(removeIfNo0(2)) t1++;
        if(removeIfNo0(0)) t1++;
        if(removeIfNo0(2)) t1++;
        if(removeIfNo0(1)) t1++;
        if(removeIfNo0(0)) t1++;
        restoreFood();
        tMax=std::max(t1, tMax);
        ///M
        t1=0;
        if(removeIfNo0(1)) t1++;
        if(removeIfNo0(2)) t1++;
        if(removeIfNo0(0)) t1++;
        if(removeIfNo0(2)) t1++;
        if(removeIfNo0(1)) t1++;
        if(removeIfNo0(0)) t1++;
        if(removeIfNo0(0)) t1++;
        restoreFood();
        tMax=std::max(t1, tMax);
        ///M
        t1=0;
        if(removeIfNo0(2)) t1++;
        if(removeIfNo0(0)) t1++;
        if(removeIfNo0(2)) t1++;
        if(removeIfNo0(1)) t1++;
        if(removeIfNo0(0)) t1++;
        if(removeIfNo0(0)) t1++;
        if(removeIfNo0(1)) t1++;
        restoreFood();
        tMax=std::max(t1, tMax);
        ///J
        t1=0;
        if(removeIfNo0(0)) t1++;
        if(removeIfNo0(2)) t1++;
        if(removeIfNo0(1)) t1++;
        if(removeIfNo0(0)) t1++;
        if(removeIfNo0(0)) t1++;
        if(removeIfNo0(1)) t1++;
        if(removeIfNo0(2)) t1++;
        restoreFood();
        tMax=std::max(t1, tMax);
        ///V
        t1=0;
        if(removeIfNo0(2)) t1++;
        if(removeIfNo0(1)) t1++;
        if(removeIfNo0(0)) t1++;
        if(removeIfNo0(0)) t1++;
        if(removeIfNo0(1)) t1++;
        if(removeIfNo0(2)) t1++;
        if(removeIfNo0(0)) t1++;
        restoreFood();
        tMax=std::max(t1, tMax);
        ///S
        t1=0;
        if(removeIfNo0(1)) t1++;
        if(removeIfNo0(0)) t1++;
        if(removeIfNo0(0)) t1++;
        if(removeIfNo0(1)) t1++;
        if(removeIfNo0(2)) t1++;
        if(removeIfNo0(0)) t1++;
        if(removeIfNo0(2)) t1++;
        restoreFood();
        tMax=std::max(t1, tMax);
        ///D
        t1=0;
        if(removeIfNo0(0)) t1++;
        if(removeIfNo0(0)) t1++;
        if(removeIfNo0(1)) t1++;
        if(removeIfNo0(2)) t1++;
        if(removeIfNo0(0)) t1++;
        if(removeIfNo0(2)) t1++;
        if(removeIfNo0(1)) t1++;
        restoreFood();
        tMax=std::max(t1, tMax);
        ans+=tMax;
    printf("%d", ans);
}