#include<bits/stdc++.h>
using namespace std;
int arr[200000];
bool received[200000];
bool notYet[200000];
set<int> ungifted;
set<int> undecided;
int main(){
	int n, i;
	cin >> n;
	for(i=0; i<n; i++){
		cin >> arr[i];
		if(arr[i]>0){
			received[arr[i]-1]=true;
		}
	}
	for(i=0; i<n; i++){
		if(!received[i]){
			ungifted.insert(i);
		}
		if(arr[i]==0){
			undecided.insert(i);
		}
	}
	auto ungiftedIt = ungifted.begin();
	auto undecidedIt = undecided.rbegin();
	while(ungiftedIt != ungifted.end()){
		int ungifted = *ungiftedIt;
		int undecided = *undecidedIt;
		//cout << undecided << " to " << ungifted+1 << endl;
		arr[undecided]=ungifted+1;
		ungiftedIt++;
		undecidedIt++;
	}
	for(i=0; i<n; i++){
		if(arr[i]-1==i){
			undecidedIt = undecided.rbegin();
			if(*undecidedIt == i){
				undecidedIt++;
			}
			arr[i]=arr[*undecidedIt];
			arr[*undecidedIt]=i+1;
		}

	}
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}