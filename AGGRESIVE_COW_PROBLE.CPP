#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> &arr,int N,int C,int minAllowedist){
    int cows = 1, lastStallPos = arr[0];
    for(int i=1;i<N;i++){
         if(arr[i]-lastStallPos >= minAllowedist){

             cows++;
            lastStallPos = arr[i];
        }
        if(cows == C){
            return true;
        }
    }
    return false;
}




int getDistance(vector<int>& arr,int N,int C ){
    sort(arr.begin(),arr.end());
    int st = 1,end = arr[N-1]-arr[0],ans = -1;

    while(st<=end){
        int mid = st+(end-st)/2;
        if(isPossible(arr,N,C,mid)){
            ans = mid;
            st = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}
int main(){
    int N = 5,C=2;
    vector<int>arr = {1,2,8,4,9};
    cout<<getDistance(arr,N,C)<<endl;
    return 0;
}





/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int>& arr,int N,int C,int minAllowedist){
    int cow = 1,lastStallPos = arr[0];

    for(int i=0;i<N;i++){
        if(arr[i]-lastStallPos>= minAllowedist){
            cow++;
            lastStallPos = arr[i];
        }
        if(cow==C){
            return true;
        }
    }
    return false;
}



int getDistance(vector<int>& arr,int N,int C,int){
    sort(arr.begin(),arr.end());
    int st = 1,end = arr[N-1]-arr[0],ans = -1;
    while(st<=end){
        int mid = st+(end-st)/2;
        if(isPossible(arr,N,C,mid)){
            ans = mid;
            st = mid+1;
        }
        else{
            end = mid-1;
        }

    }
    return ans;

}
int main(){
    int N= 5,C= 2;
    vector<int> arr = {12,34,5,6,8};
    cout<<getDistance(arr,N,C)<<endl;
    return 0;
}*/