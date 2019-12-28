    #include<bits/stdc++.h>
    using namespace std;
    int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int n, i, j;
        cin >> n;
        string s1, s2;
        bool can;
        while(n--){
            bool found=false;
            cin >> s1 >> s2;
            sort(s1.begin(), s1.end());
            for(i=0; i+s1.length()-1<s2.length() && !found; i++){
                string tmp = s2.substr(i, s1.length());
                sort(tmp.begin(), tmp.end());
                //cout << s1 << endl << tmp << endl << endl;
                if(s1==tmp){
                    found = true;
                }
            }
            cout << (found ? "YES" : "NO") << "\n";
        }
    }