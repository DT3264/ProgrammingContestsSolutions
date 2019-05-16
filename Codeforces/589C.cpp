#include<string.h>
#include<iostream>
#include<vector>
#include<queue>
#define q std::queue
#define v std::vector
#define iter std::vector<int>::iterator
struct pos{
    int next;
    int contCats;
};
int contPosibles;
bool hasCat[100001];
v<v<int>> vec(100000);
q<pos> toVisit;
int main() {
    int n, m, i, x, y;
    std::cin >> n >> m;
    for(i=0; i<n; i++){
        std::cin>> hasCat[i];
    }
    for(i=0; i<n-1; i++){
        std::cin >> x >> y;
        x--;
        y--;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    /*Sinse the house is the root and the root is not a leaf*/
    for(i=0; i<vec[0].size(); i++){
        int nextPos=vec[0][i];
        if(hasCat[0]<=m){
            toVisit.push({nextPos, hasCat[0]});
        }
        for(iter it=vec[nextPos].begin(); it!=vec[nextPos].end(); ++it){
            if(*it==0){
                vec[nextPos].erase(it);
                break;
            }
        }
    }
    pos aPos;
    while(!toVisit.empty()){
        aPos=toVisit.front();
        toVisit.pop();
        int aX=aPos.next;
        int actC=aPos.contCats+hasCat[aX];
        if(!hasCat[aX]){
            actC=0;
        }
        int actVis=0;
        if(vec[aX].size()==0 && aX!=0 && actC<=m){
            //std::cout << "can reach: " << aX+1 << " with " << actC << std::endl;
            contPosibles++;
        }
        for(i=0; i<vec[aX].size(); i++){
            int nextPos=vec[aX][i];
            if(actC+hasCat[nextPos]<=m){
                for(iter it=vec[nextPos].begin(); it!=vec[nextPos].end(); ++it){
                    if(*it==aX){
                        vec[nextPos].erase(it);
                        break;
                    }
                }
                toVisit.push({nextPos, actC});
            }
        }
    }
    std::cout << contPosibles;
    return 0;
}
