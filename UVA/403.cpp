#include<bits/stdc++.h>
using namespace std;
char sheet[60][60];
bool isValid(int x, int y){
    return x>=0 && x<60 && y>=0 && y<60;
}
void writeC1LetterAt(int x, int y, char letter){
    if(letter!=' ') sheet[x][y]=letter;
}
void writeC5LetterAt(int x, int y, char letter[5][7]){
    for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
            if(isValid(x+i, y+j) && letter[i][j]!='.'){
                sheet[x+i][y+j]=letter[i][j];
            }
        }
    }
}
void writeC5Letter(char c, int x, int y){
    if(c=='A'){
        char letter[5][7]={
        ".***..",
        "*...*.",
        "*****.",
        "*...*.",
        "*...*."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='B'){
        char letter[5][7]={
        "****..",
        "*...*.",
        "****..",
        "*...*.",
        "****.."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='C'){
        char letter[5][7]={
        ".****.",
        "*...*.",
        "*.....",
        "*.....",
        ".****."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='D'){
        char letter[5][7]={
        "****..",
        "*...*.",
        "*...*.",
        "*...*.",
        "****.."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='E'){
        char letter[5][7]={
        "*****.",
        "*.....",
        "***...",
        "*.....",
        "*****."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='F'){
        char letter[5][7]={
        "*****.",
        "*.....",
        "***...",
        "*.....",
        "*....."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='G'){
        char letter[5][7]={
        ".****.",
        "*.....",
        "*..**.",
        "*...*.",
        ".***.."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='H'){
        char letter[5][7]={
        "*...*.",
        "*...*.",
        "*****.",
        "*...*.",
        "*...*."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='I'){
        char letter[5][7]={
        "*****.",
        "..*...",
        "..*...",
        "..*...",
        "*****."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='J'){
        char letter[5][7]={
        "..***.",
        "...*..",
        "...*..",
        "*..*..",
        ".**..."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='K'){
        char letter[5][7]={
        "*...*.",
        "*..*..",
        "***...",
        "*..*..",
        "*...*."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='L'){
        char letter[5][7]={
        "*.....",
        "*.....",
        "*.....",
        "*.....",
        "*****."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='M'){
        char letter[5][7]={
        "*...*.",
        "**.**.",
        "*.*.*.",
        "*...*.",
        "*...*."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='N'){
        char letter[5][7]={
        "*...*.",
        "**..*.",
        "*.*.*.",
        "*..**.",
        "*...*."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='O'){
        char letter[5][7]={
        ".***..",
        "*...*.",
        "*...*.",
        "*...*.",
        ".***.."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='P'){
        char letter[5][7]={
        "****..",
        "*...*.",
        "****..",
        "*.....",
        "*....."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='Q'){
        char letter[5][7]={
        ".***..",
        "*...*.",
        "*...*.",
        "*..**.",
        ".****."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='R'){
        char letter[5][7]={
        "****..",
        "*...*.",
        "****..",
        "*..*..",
        "*...*."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='S'){
        char letter[5][7]={
        ".****.",
        "*.....",
        ".***..",
        "....*.",
        "****.."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='T'){
        char letter[5][7]={
        "*****.",
        "*.*.*.",
        "..*...",
        "..*...",
        ".***.."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='U'){
        char letter[5][7]={
        "*...*.",
        "*...*.",
        "*...*.",
        "*...*.",
        ".***.."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='V'){
        char letter[5][7]={
        "*...*.",
        "*...*.",
        ".*.*..",
        ".*.*..",
        "..*..."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='W'){
        char letter[5][7]={
        "*...*.",
        "*...*.",
        "*.*.*.",
        "**.**.",
        "*...*."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='X'){
        char letter[5][7]={
        "*...*.",
        ".*.*..",
        "..*...",
        ".*.*..",
        "*...*."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='Y'){
        char letter[5][7]={
        "*...*.",
        ".*.*..",
        "..*...",
        "..*...",
        "..*..."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='Z'){
        char letter[5][7]={
        "*****.",
        "...*..",
        "..*...",
        ".*....",
        "*****."
        };
        writeC5LetterAt(x, y, letter);
    }
    else if(c=='.'){
        char letter[5][7]={
        "......",
        "......",
        "......",
        "......",
        "......"
        };
        writeC5LetterAt(x, y, letter);
    }

}
void writeC1From(string str, int x, int y){
    //cout << "Writting: *" << str << "* on row " << x+1 << "; and col " << y+1 << "\n";
    int strPos=0;
    int yPos=y;
    while(strPos<str.size() && yPos<60){
        writeC1LetterAt(x, yPos, str[strPos]);
        strPos++;
        yPos++;
    }
}
void writeC5From(string str, int x, int y){
    int strPos=0;
    int yPos=y;
    while(strPos<str.size() && yPos<60){
        char actChar=str[strPos];
        writeC5Letter(actChar, x, y);
        strPos++;
        y+=6;
    }
}
void writeC1Centered(string str, int x){
    int strPos=str.size()/2;
    int yPos=30;
    while(strPos>0){
        yPos--;
        strPos--;
    }
    while(strPos<str.size() && yPos<60){
        writeC1LetterAt(x, yPos, str[strPos]);
        strPos++;
        yPos++;
    }
}
void writeC5Centered(string str, int x){
    int strPos=str.size()/2;
    int yPos= str.size()%2!=0 ? 27 : 30;
    while(strPos>0){
        yPos-=6;
        strPos--;
    }
    while(strPos<str.size() && yPos<60){
        writeC5Letter(str[strPos], x, yPos);
        strPos++;
        yPos+=6;
    }
}
void writeC1Right(string str, int x){
    int strPos=str.size()-1;
    int yPos=59;
    while(strPos>=0){
        writeC1LetterAt(x, yPos, str[strPos]);
        strPos--;
        yPos--;
    }
}
void writeC5Right(string str, int x){
    int strPos=str.size()-1;
    int yPos=54;
    while(strPos>=0){
        char actChar=str[strPos];
        writeC5Letter(actChar, x, yPos);
        strPos--;
        yPos-=6;
    }
}
void cleanSheet(){
    for(int i=0; i<60; i++){
        for(int j=0; j<60; j++){
            sheet[i][j]='.';
        }
    }
}
void printSheet(){
    for(int i=0; i<60; i++){
        for(int j=0; j<60; j++){
            cout << sheet[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
    for(int i=0; i<60; i++){
        cout << "-";
    }
    cout << "\n\n";
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    string op;
    cleanSheet();
    while(cin >> op){
        string str, font;
        int row, col;
        //cout << "OP: " << op << "*\n";
        if(op==".EOP"){
            printSheet();
            cleanSheet();
            continue;
        }
        cin >> font >> row;
        row--;
        if(op==".P"){
            cin >> col;
            col--;
        }
        getline(cin, str);
        str=str.substr(2, str.size()-3);
        //cout << "OP: " << op << "; Font: " << font << "\n";
        //cout << "Row: " << row << "; Col: " << col << "\n";
        //cout << "*" << str << "*\n";
        if(op==".P"){
            if(font=="C1"){
                writeC1From(str, row, col);
            }
            if(font=="C5"){
                writeC5From(str, row, col);
            }
        }
        if(op==".L"){
            if(font=="C1"){
               writeC1From(str, row, 0);
            }
            if(font=="C5"){
                writeC5From(str, row, 0);
            }
        }
        if(op==".R"){
            if(font=="C1"){
               writeC1Right(str, row);
            }
            if(font=="C5"){
                writeC5Right(str, row);
            }
        }
        if(op==".C"){
            if(font=="C1"){
               writeC1Centered(str, row);
            }
            if(font=="C5"){
                writeC5Centered(str, row);
            }
        }
    }
	return 0;
}
