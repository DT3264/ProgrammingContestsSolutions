#include <stdio.h>
#include<string.h>
#include<vector>
using namespace std;
long long const maxSizeQueue=1001;
struct pQueue{
    int arr[maxSizeQueue];
    int left=0;
    int right=0;
    void push(int n){
        arr[right%maxSizeQueue]=n;
        right++;
    }
    void pop(){
        left++;
    }
    int top(){
        return arr[left%maxSizeQueue];
    }
    bool isEmpty(){
        return left==right;
    }
    pQueue(){
        memset(arr, 0, sizeof(arr));
    }
}teamQ;

struct toVect{
    int team;
    pQueue qTeam;
}teamP;

vector<toVect> vec;
int onTeam[10000000];
bool isTeamOnQueue[1001];
int cantTeams, cantOnTeam, element;
int toInsert;
char operation[8];
int scenario=1;
int main(){
    int i, j;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d", &cantTeams) && cantTeams!=0){
        vec.clear();
        memset(onTeam, 0, sizeof(onTeam));
        memset(isTeamOnQueue, 0, sizeof(isTeamOnQueue));
        printf("Scenario #%d\n", scenario++);
        for(i=0; i<cantTeams; i++){
            scanf("%d", &cantOnTeam);
            for(j=0; j<cantOnTeam; j++){
                scanf("%d", &element);
                onTeam[element]=i+1;
                //printf("%d is on team %d\n", element, onTeam[element]);
            }
        }
        while(scanf("%s", operation) && strcmp(operation, "STOP")!=0){
            if(strcmp(operation, "ENQUEUE")==0){
                scanf("%d", &toInsert);
                int toTeam=onTeam[toInsert];
                if(!isTeamOnQueue[toTeam]){
                    teamQ=pQueue();
                    teamQ.push(toInsert);
                    teamP.team=toTeam;
                    teamP.qTeam=teamQ;
                    //printf("Inserting new queue for team %d\n", toTeam);
                    vec.push_back(teamP);
                    isTeamOnQueue[toTeam]=true;
                }
                else{
                    for(i=0; i<vec.size(); i++){
                        if(vec[i].team==toTeam){
                            //printf("inserting new element on team %d\n", toTeam);
                            vec[i].qTeam.push(toInsert);
                        }
                    }
                }
            }
            else if(strcmp(operation, "DEQUEUE")==0){
                printf("%d\n", vec[0].qTeam.top());
                vec[0].qTeam.pop();
                if(vec[0].qTeam.isEmpty()){
                    //printf("removed team %d\n", vec[0].team);
                    isTeamOnQueue[vec[0].team]=false;
                    vec.erase(vec.begin());
                }
            }
        }
        printf("\n");
    }
    return 0;
}
