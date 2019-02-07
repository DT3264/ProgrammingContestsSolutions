#include<stdio.h>
#include<string.h>
struct pStack{
    char arr[100000];
    int length=100000;
    int len=0;
    void push(char n){
        arr[len++]=n;
    }
    void pop(){
        len--;
    }
    char top(){
        return arr[len-1];
    }
    bool isEmpty(){
        return len==0;
    }
    pStack(){
        len=0;
        memset(arr, 0, sizeof(arr));
    }
};
char str[1002];
int main (){
    int i;
    bool isValid;
    while(scanf("%s", str)!=EOF){
        isValid=true;
        pStack myStack=pStack();
        for(i=0; str[i]; i++){
            if(str[i]=='('){
                myStack.push('(');
            }
            else if(str[i]==')'){
                if(!myStack.isEmpty()){
                    if(myStack.top()=='('){
                        myStack.pop();
                    }
                }
                else{
                    isValid=false;
                }
            }
        }
        if(!myStack.isEmpty()){
            isValid=false;
        }
        printf("%s\n", (isValid ? "correct" : "incorrect"));
    }
    return 0;
}
