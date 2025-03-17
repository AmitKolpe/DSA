#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    void merge(vector<int>& A,int m,vector<int>& B,int n){
        int indx = m+n-1, i= m-1,j=n-1;
        while(i>=0 && j>=0){
            if(A[i]>=B[j]){
                A[indx--] = A[i--];
            }
            else{
                A[indx--]= B[j--];
            }

        }
        while(j>=0){
            A[indx--]=B[j--];
        }
    }


};

int main(){

    vector<int>A = {1,2,3,0,0,0};
    vector<int>B = {4,5,6};
    int m= 3,n=3;
    Solution sol;
    sol.merge(A,m,B,n);
    cout<<"The sorted array is:"<<endl;
    for(int num:A){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;

}