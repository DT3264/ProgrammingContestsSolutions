#include<stdio.h>
#include<set>
#include<queue>
using namespace std;
struct node{
    node *prev;
    node *next;
    int val;
    int pos;
    node(int pos, int val){
        this->pos=pos;
        this->val=val;
        prev=nullptr;
        next=nullptr;
    }
};

///Send this to the set
///so it will compare the elements as it's shown
struct comparator {
    bool operator() (const node* left, const node* right) const{
        return left->val<right->val;
    }
};

int turnOf1=0;
int team[200001];
set<node*, comparator> sortedList;
int k;

void breakNode(node *nodo){
    if(nodo->next!=nullptr){
        nodo->next->prev=nodo->prev;
    }
    if(nodo->prev!=nullptr){
        nodo->prev->next=nodo->next;
    }
}

void delRecurs(node* actualNode, int n, bool toRight){
    if(n>k || actualNode== nullptr){
        return;
    }
    //printf("%d is on %d\n", actualNode->val, actualNode->pos);
    if(toRight){
        delRecurs(actualNode->next, n + 1, toRight);
    }
    else{
        delRecurs(actualNode->prev, n + 1, toRight);
    }
    team[actualNode->pos]=turnOf1+1;
    if(n>0) {
        sortedList.erase(actualNode);
        breakNode(actualNode);
    }
}

int main(){
    int i, n, a;
    scanf("%d%d", &n, &k);
    node *prevNode=nullptr;
    for(i=0; i<n; i++){
        scanf("%d", &a);
        node *nNode = new node(i, a);
        if(prevNode!=nullptr){
            prevNode->next=nNode;
        }
        nNode->prev=prevNode;
        prevNode=nNode;
        sortedList.insert(nNode);
    }
    while(!sortedList.empty()){
        ///Get the max element in the set
        auto it = sortedList.end();
        it--;
        auto actualNode = *it;
        sortedList.erase(it);
        //printf("going with %d\n", actualNode->val);
        team[actualNode->pos]=turnOf1;
        delRecurs(actualNode, 0, true);
        delRecurs(actualNode, 0, false);
        breakNode(actualNode);
        turnOf1++;
        turnOf1%=2;
    }
    for(i=0; i<n; i++){
        printf("%d", team[i]);
    }
    return 0;
}
