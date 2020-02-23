#include<bits/stdc++.h>
using namespace std;
struct Ans{
    int maxDays;
    int maxDailyKnow;
};
struct Day{
    int actualDay;
    int who;
};
vector<int> vec[25001];

Ans expand(int source){
    //cout << "Source: " << source << endl;
    vector<bool> memo(25001, false);
    queue<Day> news;
    int boomDay=1;
    int maxPersonsAtBoom=0;
    int actualDay=0;
    int actualPersons=0;
    memo[source]=true;
    news.push({0, source});
    while(!news.empty()){
        Day actPerson=news.front();
        news.pop();
        //cout << "**who: " << actPerson.who << " day: " << actPerson.actualDay << endl;
        if(actPerson.actualDay==actualDay+1){
            if(actualPersons>maxPersonsAtBoom){
                maxPersonsAtBoom=actualPersons;
                boomDay=actualDay;
            }
            //printf("on day %d %d knew\n", actPerson.actualDay-1, actualPersons);
            actualPersons=0;
            actualDay++;

        }
        for(int x : vec[actPerson.who]){
            if(!memo[x]){
                memo[x]=true;
                actualPersons++;
                //printf("told to %d, %d know\n", x, actualPersons);
                news.push({actPerson.actualDay+1, x});
            }
        }
    }

    return {maxPersonsAtBoom, boomDay+1};
}

int main(){
    int n;
    int friends, friendI;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> friends;
        for(int j=0; j<friends; j++){
            cin >> friendI;
            vec[i].push_back(friendI);
            //vec[friendI].push_back(i);
        }
    }

    int cases;
    int source;
    cin >> cases;
    while(cases--){
        cin >> source;
        if(vec[source].size()>0){
            Ans ans=expand(source);
            cout << ans.maxDays << " " << ans.maxDailyKnow << "\n";
        }
        else{
            cout << 0 << "\n";
        }
    }
    return 0;
}