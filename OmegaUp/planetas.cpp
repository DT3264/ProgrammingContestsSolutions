#include<bits/stdc++.h>
#include<iomanip>
#include<string>
#define vf std::vector<double>
int n;
double arr[1000];
vf vectAns;
double testVal(double x){
    int i;
    double total=0;
    for(i=0; i<n; i++){
        total+=1/(arr[i]-x);
    }
    return total;
}
int main(){
    int i;
    std::cin >> n;
    for(i=0; i<n; i++){
        std::cin >> arr[i];
    }
    std::sort(arr, arr+n);
    for(i=1; i<n; i++){
        double left=arr[i-1];
        double right=arr[i];
        double lastMid=0;
        while(left<right){
            double mid=left+(right-left)/2;
            double actVal=testVal(mid);
            if(lastMid==mid){
                vectAns.push_back(mid);
                break;
            }
            if(actVal>0){
                right=mid;
            }
            else{
                left=mid;
            }
            lastMid=mid;
        }

    }
    std::cout << n-1 << "\n";
    for(i=0; i<vectAns.size(); i++){
        std::cout << std::setprecision(3) << std::fixed << vectAns[i] << " ";
    }
    std::cout << "\n";
    return 0;
}