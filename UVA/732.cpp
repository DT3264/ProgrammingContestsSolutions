#include<stdio.h>
#include<string.h>
#include<stack>
#include<vector>
using namespace std;
struct permu{
    int actPosSrc;
    int actPosDest;
    stack<char>actualStack;
    vector<char> ans;
    permu(){
        actPosSrc=0;
        actPosDest=0;
        while(!actualStack.empty()){
            actualStack.pop();
        }
        ans.clear();
    }
};
char src[1000000];
char dest[1000000];
int srcLen, destLen;
permu resPermu;
void anagram(permu actPermu){
    while(actPermu.actPosSrc!=srcLen){
        while(!actPermu.actualStack.empty() && actPermu.actualStack.top()==dest[actPermu.actPosDest]){
            ///Push next and send to recursion
            actPermu.actualStack.push(src[actPermu.actPosSrc++]);
            actPermu.ans.push_back('i');
            anagram(actPermu);
            ///Revert the push
            actPermu.actualStack.pop();
            actPermu.actPosSrc--;
            actPermu.ans.pop_back();
            ///And complete the actual pop
            actPermu.actualStack.pop();
            actPermu.ans.push_back('o');
            actPermu.actPosDest++;
        }
        actPermu.actualStack.push(src[actPermu.actPosSrc++]);
        actPermu.ans.push_back('i');
    }
    while(!actPermu.actualStack.empty() && actPermu.actualStack.top()==dest[actPermu.actPosDest]){
        actPermu.actualStack.pop();
        actPermu.ans.push_back('o');
        actPermu.actPosDest++;
    }
    if(actPermu.ans.size()==srcLen*2){
        for(int i=0; i<actPermu.ans.size(); i++){
            printf("%c", actPermu.ans[i]);
            if(i<actPermu.ans.size()-1){
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(){
    while(scanf("%s%s", src, dest)!=EOF){
        srcLen=strlen(src);
        destLen=strlen(dest);
        printf("[\n");
        if(srcLen==destLen){
            resPermu = permu();
            anagram(resPermu);
        }
        printf("]\n");
    }
    return 0;
}
