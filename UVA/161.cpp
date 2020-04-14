#include<bits/stdc++.h>
using namespace std;
int maxTime=18001;
vector<int> vals;
vector<int> signals;
vector<int> sigCount;
void fillTimeSpace(int actVal, int signalTime){
    //cout << "Act: " << actVal << "; Signal every: " << signalTime << "\n";
    while(actVal<=maxTime){
        for(int actTime=actVal; actTime<actVal+signalTime-5 && actTime<=maxTime; actTime++){
            sigCount[actTime]++;
        }
        actVal+=signalTime*2;
        //cout << actVal << "\n";
        //system("pause");
    }
}
int findSignalsIntersection(){
    sigCount.assign(maxTime+1, 0);
    fillTimeSpace(signals[0]*2, signals[0]);
    for(int i=1; i<signals.size(); i++){
        fillTimeSpace(0, signals[i]);
    }
    for(int i=signals[0]+1; i<maxTime; i++){
        if(sigCount[i]==signals.size()){
            return i;
        }
    }
    return 0;///Unreachable val
}
void printHour(int seconds){
    if(seconds>=maxTime || seconds==0){
        cout << "Signals fail to synchronise in 5 hours\n";
        return;
    }
    //cout << seconds << "\n";
    int hours=seconds/3600;
    seconds-=hours*3600;
    int minutes=seconds/60;
    seconds-=minutes*60;
    printf("%.2d:%.2d:%.2d\n", hours, minutes, seconds);
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int val;
    while(cin >> val){
        vals.push_back(val);
    }
    for(int i=0; i<vals.size()-3; i++){
        if(vals[i]!=0){
            signals.push_back(vals[i]);
        }
        else{
            ///Aquí pasa la magia
            sort(signals.begin(), signals.end());
            int time=findSignalsIntersection();
            printHour(time);
            signals.resize(0);
        }
    }
	return 0;
}
