    #include<bits/stdc++.h>
    using namespace std;
    int n;
    int arr[100001];
    int ans[100001];
    bool ansFound=false;
    bool testAns(){
        int left, right;
        for(int i=0; i<n; i++){
            left=i-1;
            if(left<0){
                left+=n;
            }
            right=i+1;
            if(right>=n){
                right-=n;
            }
            if(ans[left]+ans[right]<=ans[i]){
                return false;
            }
        }
        return true;
    }
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr, arr+n);
        deque<int> deq;
        deq.push_front(arr[0]);
        int ind=1;
        while(ind<n){
            int left=arr[ind];
            deq.push_front(left);
            if(ind+1<n){
                int right=arr[ind+1];
                deq.push_back(right);
            }
            ind+=2;
        }
        ind=0;
        while(!deq.empty()){
            ans[ind++]=deq.front();
            deq.pop_front();
        }
        ansFound=testAns();
        if(ansFound){
            cout << "YES\n";
            for(int i=0; i<n; i++){
                cout << ans[i] << " ";
            }
        }
        else{
            cout << "NO\n";
        }
        return 0;
    }