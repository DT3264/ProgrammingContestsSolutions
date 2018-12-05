#include<stdio.h>
int track1[2000], track2[2000];
bool canArrive;
int n, k;
void getTrain(int pos, bool isTrack1){
    if(pos<0 || pos>=n) return;
    if(!isTrack1 && pos==k && track2[pos]!=0) canArrive=true;
    if(isTrack1 && pos==k && track1[pos]!=0) canArrive=true;
    if(canArrive) return;
    if(isTrack1){///if is a valid train
        getTrain(pos+1, true);///Go foward
        if(pos>=k && track2[pos]!=0 && track1[pos]!=0)///Both lines are available so the guy can cross
        getTrain(pos, false);///Get the line of the right
    }
    if(!isTrack1){
        getTrain(pos-1, false);///Go backwards
    }
}


int main (){
    int i;
    scanf("%d%d", &n, &k);
    k--;///Base 0
    for(i=0; i<n; i++){
        scanf("%d", &track1[i]);
    }
    for(i=0; i<n; i++){
        scanf("%d", &track2[i]);
    }
    if(track1[0]!=0)///if can start
        getTrain(0, true);
    printf(canArrive ? "YES" : "NO");
    return 0;
}
