#include<bits/stdc++.h>
#define f first
#define s second
#define vi vector<int>
#define pii pair<int, int>
#define ll long long
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    while(cin >> str){
        string buff="";
        char lastControl='-';
        deque<string> q;
        for(char &c : str){
            if(c=='[' || c==']'){
                ///To the begin
                if(lastControl==']' && buff.size()>0){
                    q.push_back(buff);
                    buff="";
                }
                else if((lastControl=='[' || lastControl=='-') && buff.size()>0){
                    q.push_front(buff);
                    buff="";
                }
                lastControl=c;
            }
            else{
                buff+=c;
            }
        }
        if(lastControl==']' && buff.size()>0){
            q.push_back(buff);
        }
        else if((lastControl=='[' || lastControl=='-') && buff.size()>0){
            q.push_front(buff);
        }
        while(!q.empty()){
            cout << q.front();
            q.pop_front();
        }
        cout << "\n";
    }
    return 0;
}
