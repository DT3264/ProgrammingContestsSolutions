#include<bits/stdc++.h>
using namespace std;
int maxN=100001;
int dp[100001];
int parent[100001];
int main(){
    int maxTime, songCount;
    while(cin >> maxTime){
        cin >> songCount;
        vector<int> songs(songCount);
        memset(dp, -1, sizeof(dp));
        memset(parent, -1, sizeof(parent));
        for(int &x : songs){
            cin >> x;
        }
        for(int songTime : songs){
            //printf("X: %d\n", x);
            for(int i=maxTime; i>0; i--){
				//Si con mi canción y lo que llevo 
				//puedo llegar al inicio o más adelante y no he pasado or ahí
                if(i-songTime>=0 && dp[i]==-1){
                    if(i==songTime){///Si mi posición actual es igual a la duración de la canción
                        dp[i]=songTime;///Puedo llegar a esa pos con esa canción
                        parent[i]=songTime;///Y esa canción es su propio padre
                    }
                    if(dp[i-songTime]!=-1){//Si puedo llegar hasta una posición donde termina una canción
                        dp[i]=songTime;///Puedo llegar a esa pos con esa canción
                        parent[i]=i-songTime;//Y vengo del minuti i-duracion
                    }
                }
            }
        }
        vector<int> ans;
        int sum=0, pos=-1;
        for(int i=maxTime; i>0 && pos==-1; i--)
            if(dp[i]!=-1){{///Busco de mi respuesta para atrás cual es la última posición válida
                pos=i;
            }
        }
        while(pos>0){
            ans.push_back(dp[pos]);
            pos=(parent[pos]==pos ? 0 : parent[pos]);
        }
        for(int i=ans.size()-1; i>=0; i--){
            sum+=ans[i];
            printf("%d ", ans[i]);
        }
        printf("sum:%d\n", sum);
    }
    return 0;
}
