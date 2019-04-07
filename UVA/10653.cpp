#include<stdio.h>
#include<string.h>
#define isValid(x,y) (x>=0 && x<n && y>=0 &&y<m)
struct Pos{
    int x;
    int y;
    int val;
    Pos(int x, int y, int val){
        this->x=x;
        this->y=y;
        this->val=val;
    }
    Pos(){}
};
struct Node{
    Node *next;
    Pos pos;
    Node(Pos p){
        pos=p;
        next=NULL;
    }
};
struct pQueue{
    Node *head;
    Node *tail;
    bool isEmpty(){
        return head==NULL;
    }
    void push(Pos p){
        Node *newNode = new Node(p);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=tail=tail->next;
        }
    }
    void pop(){
        Node *tempNode=head;
        head=head->next;
        delete tempNode;
    }
    Pos front(){
        return head->pos;
    }
    pQueue(){
        head=NULL;
    }
    void restart(){
        while(head!=NULL){
            pop();
        }
    }
};
bool mapa[1000][1000];
int visited[1000][1000];
int n, m;
int rows;
int row, minesInRow;
int col;
int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};

int main(){
    Pos start, dest, aPos;
    int i, j;
    pQueue cola=pQueue();
    while(scanf("%d%d", &n, &m) && n!=0 && m!=0){
        memset(mapa, 0, sizeof(mapa));
        memset(visited, -1, sizeof(visited));
        cola.restart();
        scanf("%d", &rows);
        while(rows--){
            scanf("%d%d", &row, &minesInRow);
            while(minesInRow--){
                scanf("%d", &col);
                mapa[row][col]=true;
            }
        }
        scanf("%d%d", &start.x, &start.y);
        scanf("%d%d", &dest.x, &dest.y);
        start.val=0;
        cola.push(start);
        int x, y, v;
        int nX, nY, nV;
        while(!cola.isEmpty()){
            aPos=cola.front();
            cola.pop();
            x=aPos.x, y=aPos.y, v=aPos.val;
            if(visited[x][y]==-1 || v<visited[x][y]){
                visited[x][y]=v;
                for(i=0; i<4; i++){
                    nX=x+dx[i];
                    nY=y+dy[i];
                    if(isValid(nX, nY) && !mapa[nX][nY]){
                        cola.push(Pos(nX, nY, v+1));
                    }
                }
            }
        }
        printf("%d\n", visited[dest.x][dest.y]);
    }
    return 0;
}
