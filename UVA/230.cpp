#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define vi vector<ll>
#define pii pair<ll, ll>
#define debug if(printDebug)
using namespace std;
bool printDebug=false;
struct Book{
    string name;
    string author;
    char state;
    Book(string str){
        bool toName=true;
        for(int i=1; i<str.size(); i++){
            if(toName){
                if(str[i]=='"'){
                    i+=4;
                    toName=false;
                    continue;
                }
                this->name+=str[i];
            }
            else{
                this->author+=str[i];
            }
        }
        state='S';
    }
};
int main(){
    //printDebug=true;
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);//*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);//*/
    string str;
    vector<Book> books;
    while(getline(cin, str) && str!="END"){
        books.push_back(Book(str));
    }
    sort(books.begin(), books.end(), [](const Book &b1, const Book &b2){
        if(b1.author<b2.author) return true;
        else if(b1.author==b2.author){
            return b1.name<b2.name;
        }
        else return false;
    });
    string book;
    while(getline(cin, str) && str!="END"){
        if(str[0]!='S'){
            book=str.substr(8, str.size()-9);
            for(auto &b : books){
                if(b.name==book){
                    //cout << b.name << "->" << str[0] << "\n";
                    b.state=str[0];
                    break;
                }
            }
        }
        else{
            int booksPrev=0;
            int lastBook=0;
            for(int i=0; i<books.size(); i++){
                if(books[i].state=='R'){
                    if(booksPrev==0){
                        cout << "Put \"" << books[i].name << "\" first\n";
                    }
                    else{
                        cout << "Put \"" << books[i].name << "\" after \"" << books[lastBook].name << "\"\n";
                    }
                    books[i].state='S';
                }
                if(books[i].state=='S'){
                    booksPrev++;
                    lastBook=i;
                }
            }
            cout << "END\n";
        }
    }
    return 0;

}
