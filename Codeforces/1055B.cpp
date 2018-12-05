#include<stdio.h>
long long hairs[200000];
bool cut[200000];
int n, m, l, i;
int op, p, d;
int totalCuts=0;
int checkSides(int pos){
    if(hairs[pos]>l){
        if(!cut[pos]){
            if(pos==1){///Only check right
                if(!cut[pos+1]){
                    totalCuts++;
                }
                else if(cut[pos+1]){
                    ///Nothing because it doesn't join two sections
                }
            }
            else if(pos==n){///Only check left
                if(!cut[pos-1])
                    totalCuts++;
                else if(cut[pos-1]){
                    ///Nothing because it doesn't join two sections
                }
            }
            else{///Check both sides
                if(!cut[pos-1] && !cut[pos+1])
                    totalCuts++;
                else if(cut[pos-1] && cut[pos+1])
                    totalCuts--;
            }
        }
        cut[pos]=true;
    }
}
int main (){
    scanf("%d%d%d", &n, &m, &l);
    for(i=1; i<=n; i++){
        scanf("%d", &hairs[i]);
        checkSides(i);
    }

    for(i=0; i<m; i++){
        scanf("%d", &op);
        if(op==0){
            printf("%d\n", totalCuts);
        }
        else if(op==1){
            scanf("%d%d", &p, &d);
            hairs[p]+=d;
            checkSides(p);
        }
    }
    return 0;
}
