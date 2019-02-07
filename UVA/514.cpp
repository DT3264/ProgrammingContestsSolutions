#include<stdio.h>
#include<string.h>
struct pStack{
    int pos=0;
    int arr[1001];
    void push(int n){
        arr[pos++]=n;
    }
    void pop(){
        pos--;
    }
    int top(){
        return arr[pos-1];
    }
    bool isEmpty(){
        return pos==0;
    }
    pStack(){
        pos=0;
    }
};
int wOrder[1001];
int n;
void solve(){
    pStack station=pStack(), b=pStack(), a=pStack();
    int i, actualPos;
    bool canBeDone;
    int lastTop;
    canBeDone=true;
    actualPos=0;
    for(i=n; i>=1; i--){
        a.push(i);
    }
    while(actualPos<n && canBeDone){
        if(actualPos>0){
            lastTop=b.top();
        }
        if(!station.isEmpty()){
            if(station.top()==wOrder[actualPos]){
                while(station.top()==wOrder[actualPos]){
                    //printf("inserting from station %d\n", station.top());
                    b.push(station.top());
                    station.pop();
                    actualPos++;
                }
            }
        }
        if(!a.isEmpty()){
            while(a.top()!=wOrder[actualPos] && a.top()<=n){
                //printf("pushing to station %d\n", a.top());
                station.push(a.top());
                a.pop();
            }
            if(a.top()==wOrder[actualPos]){
                //printf("inserting %d\n", a.top());
                b.push(a.top());
                a.pop();
                actualPos++;
            }
        }
        if(actualPos>0){
            if(lastTop==b.top()){
                canBeDone=false;
            }
        }
    }
    printf("%s\n", (canBeDone ? "Yes" : "No"));
}

int main (){
    int i;
    //freopen("out.txt", "w", stdout);
    while(scanf("%d", &n) && n!=0){
        while(scanf("%d", &wOrder[0]) && wOrder[0]!=0){
            for(i=1; i<n; i++){
                scanf("%d", &wOrder[i]);
            }
            solve();
        }
        printf("\n");
    }
    return 0;
}
