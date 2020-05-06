#include<bits/stdc++.h>
#define f first
#define s second
#define vi vector<int>
#define pii pair<int, int>
#define ll long long
using namespace std;
struct Problem{
    int team;
    int problem;
    int time;
    string status;
};
struct Team{
    int team;
    int problems;
    int time;
    bool hasSubmissions=false;
};
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int cases;
    string str;
    cin >> cases;
    cin.ignore();
    getline(cin, str);
    while(cases--){
        vector<vi> points(101, vi(10, 0));
        vector<vi> solved(101, vi(10, 0));
        vector<Team> teams(101);
        for(int i=1; i<teams.size(); i++){
            teams[i].team=i;
            teams[i].problems=0;
            teams[i].time=0;
        }
        Problem p;
        while(getline(cin, str) && str!=""){
            stringstream ss(str);
            ss >> p.team >> p.problem >> p.time >> p.status;
            if(p.status[0]=='I'){
                points[p.team][p.problem]+=20;
            }
            if(p.status[0]=='C' && !solved[p.team][p.problem]){
                points[p.team][p.problem]+=p.time;
                solved[p.team][p.problem]=true;
                teams[p.team].problems++;
                teams[p.team].time+=points[p.team][p.problem];
            }
            teams[p.team].hasSubmissions=true;
        }
        sort(teams.begin(), teams.end(), [](const Team &t1, const Team &t2){
             if(t1.problems>t2.problems) return true;
             else if(t1.problems==t2.problems){
                if(t1.time!=t2.time){
                    return t1.time<t2.time;
                }
                else if(t1.time==t2.time){
                    return t1.team<t2.team;
                }
             }
             else if(t1.problems<t2.problems) return false;
        });
        for(int i=0; i<teams.size(); i++){
            if(teams[i].hasSubmissions){
                cout << teams[i].team << " " << teams[i].problems << " " << teams[i].time << "\n";
            }
        }
        if(cases>0){
            cout << "\n";
        }
    }
    return 0;
}
