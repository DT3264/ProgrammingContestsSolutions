#include<bits/stdc++.h>
using namespace std;
struct Proposal{
    string name;
    double price;
    double complaince;
    int index;
};
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, m;
    int nCase=1;
    string s;
    while((cin >> n >> m) && n!=0 && m!=0){
        if(nCase>1){
            cout << "\n";
        }
        cin.ignore();
        for(int i=0; i<n; i++){
            getline(cin, s);
        }
        vector<Proposal> proposals(m);
        int proposalCont=0;
        for(auto &p : proposals){
            getline(cin, p.name);
            cin >> p.price;
            double propRequirements;
            cin >> propRequirements;
            cin.ignore();
            vector<string> requirements(propRequirements);
            for(int i=0; i<propRequirements; i++){
                getline(cin, s);
            }
            p.complaince=propRequirements/(double)n;
            p.index=proposalCont++;
        }
        sort(proposals.begin(), proposals.end(), [](Proposal &p1, Proposal &p2){
            if(p1.complaince>p2.complaince){
                return true;///Conviene más
             }
             if(p1.complaince==p2.complaince){
                if(p1.price<p2.price){
                    return true;///Menor precio
                }
                else if(p1.price==p2.price){
                    return p1.index<p2.index;///Va primero
                }
                return false;
             }
             return false;
        });
        cout << "RFP #" << nCase++ << "\n";
        cout << proposals[0].name << "\n";
    }
	return 0;
}
