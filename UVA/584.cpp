#include<bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    char frame1, frame2;
    while(getline(cin, line) && line!="Game Over"){
        stringstream ss(line);
        vector<pii> vec;
        int pos=0;
        while(ss >> frame1){
            frame2='0';
            int v1=-1, v2=-1;
            if(frame1=='X'){///If is strike
                v1=10;
                if(vec.size()==10 && vec[9].f==10){
                    ss >> frame2;
                    if(frame2=='X') v2=10;
                    else v2=frame2-'0';
                }
            }
            if(frame1!='X'){
                v1=frame1-'0';
                if(vec.size()<10){
                    ss >> frame2;
                }
                if(vec.size()==10 && vec[9].f==10){
                    ss >> frame2;
                }
                if(frame2=='/'){///If is spare
                    v2=10-v1;
                }
                else{///If is regular shot
                    v2=frame2-'0';
                }
            }
            //cout << "Shot: " << vec.size() << "\n";
            //cout << v1 << " - " << v2 << "\n";
            vec.push_back({v1, v2});
        }
        for(int i=9; i>=0; i--){
            if(vec[i].s==-1 && i+1<vec.size()){
                vec[i].s=vec[i+1].f;
            }
        }

        int points=0;
        for(int i=0; i<10; i++){
            if(vec[i].f==10){///Points from strike
                points+=vec[i].f+vec[i+1].f+vec[i+1].s;
            }
            else if(vec[i].f+vec[i].s==10){///Points from spare
                points+=vec[i].f+vec[i].s+vec[i+1].f;
            }
            else{///Points w/out bonus
                points+=vec[i].f+vec[i].s;
            }
        }
        cout << points << "\n";

    }
	return 0;
}
