#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<ll>
#define pii pair<ll, ll>
#define debug if(printDebug)
using namespace std;
struct Bound{
    int lower;
    int upper;
    int size;
};
struct Array{
    string name;
    int base, size, dimension;
    vector<Bound> dimensions;
    vector<int> cd;
    int c;
    void calcC(){
        cd=vector<int>(dimension+1, 0);
        int pos=dimension;
        cd[0]=base;
        cd[pos]=size;
        cd[0]-=cd[pos]*dimensions[pos].lower;
        pos--;
        while(pos>0){
            cd[pos]=cd[pos+1]*(dimensions[pos+1].upper-dimensions[pos+1].lower+1);
            cd[0]-=cd[pos]*dimensions[pos].lower;
            pos--;
        }
        c=cd[0];
    }
};
bool printDebug=false;
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    int n, m;
    cin >> n >> m;
    vector<Array> arrays(n);
    for(auto &a : arrays){
        cin >> a.name >> a.base >> a.size >> a.dimension;
        a.dimensions.resize(a.dimension+1);
        for(int i=1; i<a.dimensions.size(); i++){
            cin >> a.dimensions[i].lower >> a.dimensions[i].upper;
        }
        a.calcC();
    }
    for(int i=0; i<m; i++){
        string name;
        int addr;
        int ind=0;
        int d, dim;
        cin >> name;
        for(int j=0; j<arrays.size(); j++){
            if(arrays[j].name==name){
                ind=j;
                break;
            }
        }
        dim=arrays[ind].dimension;
        addr=arrays[ind].cd[0];
        cout << name << "[";
        for(int j=0; j<dim; j++){
            cin >> d;
            cout << d;
            if(j<dim-1) cout << ", ";
            addr+=arrays[ind].cd[j+1]*d;
        }
        cout << "] = " << addr << "\n";
    }
    return 0;

}
