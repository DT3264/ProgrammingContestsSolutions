#include <bits/stdc++.h>
using namespace std;
int *connected;
bool *visited;
vector< vector<int> > vec;
vector<int> conections;
vector<int> altCon;
void visit(int actualPos){
    if(!visited[actualPos]){
        visited[actualPos]=true;
        if(!connected[actualPos]){
            connected[actualPos]=true;
            //printf("from %d\n", actualPos);
            conections.push_back(actualPos);
            for(int i=0; i<vec[actualPos].size(); i++){
                if(!connected[vec[actualPos][i]]){
                    connected[vec[actualPos][i]]=true;
                    //printf("connected %d\n", vec[actualPos][i]);
                    visit(vec[actualPos][i]);
                    altCon.push_back(vec[actualPos][i]);
                }

            }
        }
        else{
            for(int i=0; i<vec[actualPos].size(); i++){
                visit(vec[actualPos][i]);
            }
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int cases;
    int i;
    int n, m;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d%d", &n, &m);
        connected=new int[n+1]();
        visited=new bool[n+1]();
        vec=vector< vector<int> >(n+1);
        conections=vector<int>();
        altCon=vector<int>();
        int v, u;
        for(i=0; i<m; i++){
            scanf("%d%d", &v, &u);
            vec[v].push_back(u);
            vec[u].push_back(v);
        }
        visit(vec[u][0]);
        vector<int> *vAns;
        if(conections.size()<=n/2){
            vAns=&conections;
        }
        else{
            vAns=&altCon;
        }
        printf("%d\n", (*vAns).size());
        for(i=0; i<(*vAns).size(); i++){
            printf("%d ", (*vAns)[i]);
        }
        printf("\n");
    }
}
