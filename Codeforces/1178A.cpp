#include<bits/stdc++.h>
using namespace std;
struct party{
    int ind;
    int seats;
};

bool sortBySeats(party &p1, party &p2){
    return p1.seats<p2.seats;
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    party parties[101];
    int n, i, totalSeats=0;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &parties[i].seats);
        parties[i].ind=i;
        totalSeats+=parties[i].seats;
    }
    vector<int> ans;
    int partySeatsBegin=parties[0].seats;
    int partySeatsTotal=partySeatsBegin;
    ans.push_back(0);
    sort(parties, parties+n, sortBySeats);
    for(i=0; i<n; i++){
        if(parties[i].ind==0){
            continue;
        }
        int actualParty=parties[i].seats;
        int actualInd=parties[i].ind;
        //printf("actualSeats: %d, half: %d, candidate: %d\n", partySeatsBegin, partySeatsBegin/2, actualParty);
        if(actualParty<=(partySeatsBegin/2)){
            partySeatsTotal+=actualParty;
            ans.push_back(actualInd);
        }
    }
    sort(ans.begin(), ans.end());
    if(partySeatsTotal>=(totalSeats/2)+1){
        printf("%d\n", ans.size());
        for(i=0; i<ans.size(); i++){
            printf("%d ", ans[i]+1);
        }
    }
    else{
        printf("0");
    }
    printf("\n");
    return 0;
}
