#include <iostream>

using namespace std;

int kids[1000];
int height;
int nKids;
int width;

int main()
{
    cin >> nKids >> height;
    int i;
    for(i=0; i<nKids; i++)
        cin >> kids[i];
    for(i=0; i<nKids; i++){
        if(kids[i]>height) width+=2;
        else width++;
    }
    cout << width;
	return 0;
}
