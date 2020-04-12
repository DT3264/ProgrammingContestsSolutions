#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d, n;
    int nCase=1;
    while(cin >> n && n!=0){
        cout << "Case " << nCase++ << ":\n";
        int val, sum=0;
        for(int i=0; i<n; i++){
            cin >> val;
            sum+=val;
        }
        double avg = sum/(double)n;
        int num = abs(sum % n);
        int den = n;
        int gcd = __gcd(num, den);
        num /= gcd;
        den /= gcd;
        bool isNeg=avg<0;
        bool isFrac=num!=0;
        bool isInt=abs(avg)>=1 || (!isFrac && avg==0);
        vector<vector<char>> vec(3, vector<char>());
        if(isNeg){
            vec[0].push_back(' ');
            vec[0].push_back(' ');
            vec[1].push_back('-');
            vec[1].push_back(' ');
            vec[2].push_back(' ');
            vec[2].push_back(' ');
        }
        if(isInt){
            string numStr = to_string((int)floor(abs(avg)));
            for(char c : numStr){
                vec[0].push_back(' ');
                vec[1].push_back(c);
                vec[2].push_back(' ');
            }
        }
        if(isFrac){
            string n1=to_string(num);
            string n2=to_string(den);
            for(char c : n2){
                vec[0].push_back(' ');
                vec[1].push_back('-');
                vec[2].push_back(c);
            }
            int n1Pos=n1.size()-1;
            int vecPos=vec[0].size()-1;
            while(n1Pos>=0){
                vec[0][vecPos--]=n1[n1Pos--];
            }
        }
        if(isFrac){
            for(int i=0; i<3; i++){
                for(char c : vec[i]){
                    cout << c;
                }
                cout << "\n";
            }
        }
        else{
            for(char c : vec[1]){
                cout << c;
            }
            cout << "\n";
        }
        //cout << "\n";
    }
	return 0;
}
