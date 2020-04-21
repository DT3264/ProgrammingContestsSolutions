#include<bits/stdc++.h>
using namespace std;
vector<string> findPosibleChilds(string &p1, string &p2){
    set<string> posibles={"A", "B", "AB", "O"};
    vector<string> toReturn;
    if(p1=="A"){
        if(p2=="A" || p2=="O"){
            posibles.erase("B");
            posibles.erase("AB");
        }
        if(p2=="AB"){
            posibles.erase("O");
        }
    }
    else if(p1=="B"){
        if(p2=="B" || p2=="O"){
            posibles.erase("AB");
        }
        if(p2=="B"){
            posibles.erase("A");
        }
        if(p2=="AB"){
            posibles.erase("O");
        }
    }
    else if(p1=="AB"){
        posibles.erase("O");
        if(p2=="O"){
            posibles.erase("AB");
        }
    }

    else if(p1=="O"){
        posibles.erase("AB");
        if(p2=="A"){
            posibles.erase("B");
        }
        if(p2=="B"){
            posibles.erase("A");
        }
        if(p2=="AB"){
            posibles.erase("AB");
            posibles.erase("O");
        }
        if(p2=="O"){
            posibles.erase("A");
            posibles.erase("B");
        }
    }
    for(string s : posibles){
        toReturn.push_back(s);
    }
    return toReturn;
}
vector<string> findPosibleParent(string p, string child){
    set<string> posibles={"A", "B", "AB", "O"};
    vector<string> toReturn;
    if(p=="A"){
        if(child=="B"){
            posibles.erase("A");
            posibles.erase("O");
        }
        if(child=="AB"){
            posibles.erase("A");
            posibles.erase("O");
        }
        if(child=="O"){
            posibles.erase("AB");
        }
    }
    if(p=="B"){
        if(child=="A"){
            posibles.erase("B");
            posibles.erase("O");
        }
        if(child=="AB"){
            posibles.erase("B");
            posibles.erase("O");
        }
        if(child=="O"){
            posibles.erase("AB");
        }
    }
    if(p=="AB"){
        if(child=="AB"){
            posibles.erase("O");
        }
        if(child=="O"){
            posibles.clear();
        }
    }
    if(p=="O"){
        if(child=="A"){
            posibles.erase("B");
            posibles.erase("O");
        }
        if(child=="B"){
            posibles.erase("A");
            posibles.erase("O");
        }
        if(child=="O"){
            posibles.erase("AB");
        }
        if(child=="AB"){
            posibles.clear();
        }
    }
    for(string s : posibles){
        toReturn.push_back(s);
    }
    return toReturn;
}
void printType(string type, int rh){
    if(rh==-1){
        cout << type << "+";
    }
    else if(rh>=0){
        cout << type << "+";
        cout << ", " << type << "-";
    }
    else{
        cout << type << "-";
    }
}
void printAns(vector<string> &ans, int totalRH){
    if(ans.size()>1){
        cout << "{";
        printType(ans[0], totalRH);
        for(int i=1; i<ans.size(); i++){
            cout << ", ";
            printType(ans[i], totalRH);
        }
        cout << "}";
    }
    else if(ans.size()==1){
        if(totalRH>=0){
            cout << "{";
            printType(ans[0], totalRH);
            cout << "}";
        }
        else{
            cout << ans[0] << "-";
        }
    }
    else{
        cout << "IMPOSSIBLE";
    }
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int actCase=1;
    string p1, p2, child;
    vector<string> ans;
    while(cin >> p1 >> p2 >> child){
        vector<string> ans;
        if(p1=="E" && p2=="N" && child=="D"){
            break;
        }
        cout << "Case " << actCase++ << ": ";
        if(child=="?"){
            int totalRH=0;
            string tmpP1=p1.substr(0, p1.size()-1);
            string tmpP2=p2.substr(0, p2.size()-1);
            totalRH+=(p1[p1.size()-1]=='+' ? 1 : -1);
            totalRH+=(p2[p2.size()-1]=='+' ? 1 : -1);
            ans=findPosibleChilds(tmpP1, tmpP2);
            cout << p1 << " " << p2 << " ";
            printAns(ans, totalRH);
        }
        else{
            int totalRH=1;
            string knownParent=p1!="?" ? p1 : p2;
            string tmpParent=knownParent.substr(0, knownParent.size()-1);
            string tmpChild=child.substr(0, child.size()-1);
            bool isParentNeg=knownParent[knownParent.size()-1]=='-';
            bool isChildNeg=child[child.size()-1]=='-';
            //cout << "Going with RH: " << totalRH << "\n";
            if(isParentNeg && !isChildNeg){
                totalRH=-1;
            }
            //cout << "FInding for: " << tmpParent << ", " << tmpChild << "\n";
            ans=findPosibleParent(tmpParent, tmpChild);
            if(p1!="?"){
                cout << p1 << " ";
                printAns(ans, totalRH);
                cout << " " << child;
            }
            else{
                printAns(ans, totalRH);
                cout << " " << p2 << " " << child;
            }
        }
        cout << "\n";
    }
	return 0;

}
