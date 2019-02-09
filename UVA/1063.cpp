#include<stdio.h>
#include<string.h>
struct pStack{
    int pos=0;
    char arr[10000];
    void push(char s){
        arr[pos++]=s;
    }
    void pop(){
        pos--;
    }
    char top(){
        return arr[pos-1];
    }
    bool isEmpty(){
        return pos==0;
    }
    void reverseStack(){
        char tmp[10000];
        memcpy(tmp, arr, sizeof(arr));
        for(int i=0; i<pos; i++){
            arr[i]=tmp[pos-1-i];
        }
    }
    void init(){
        pos=0;
        memset(arr, 0, sizeof(arr));
    }
};
int n, charPos;
char desired[10000];
pStack first, station, last;
bool canBeMade;
int main (){
    int i;
    char t, lastChar;
    while(scanf("%d", &n) && n!=0){
        first.init();
        station.init();
        last.init();
        charPos=0;
        for(i=0; i<n; i++){
            scanf(" %c", &t);
            first.push(t);
        }
        first.reverseStack();
        for(i=0; i<n; i++){
            scanf(" %c", &desired[i]);
        }
        canBeMade=true;
        while(1){
            if(!station.isEmpty()){
                while(!station.isEmpty() && station.top()==desired[charPos]){
                    last.push(station.top());
                    station.pop();
                    charPos++;
                    printf("R");
                }
            }
            if(!first.isEmpty()){
                station.push(first.top());
                first.pop();
                printf("I");
            }
            ///Compare to the station stack instead the first or last 
            ///since there could be a double insertion in station and therefore last would be the same
            ///or could be a double delete to the station  and therefore first would be the same
            if(charPos>0){
                if(lastChar==station.top()){
                    break;
                }
            }
            lastChar=station.top();
        }
        for(i=0; i<n && canBeMade; i++){
            if(desired[i]!=last.arr[i]){
                canBeMade=false;
            }
        }
        if(!canBeMade){
            printf(" Impossible");
        }
        printf("\n");
    }
    return 0;
}
