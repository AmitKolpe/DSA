#include<iostream>
#include<vector>
using namespace std;

bool isvalid(vector<int>& array,int n,int m,int maxAllowedpages){
    int student = 1,pages =0;
    for(int i=0;i<n;i++){
        if(array[i]>maxAllowedpages){
            return false;
        }
        if(pages+array[i]>maxAllowedpages){
            student++;
            pages += array[i];

        }
        if(student>m){
            return false;
        }
        else{
            pages +=array[i];
        }
    } 
    return true;
}
int  AllocateBook(vector<int>& array,int m,int n){
    if(m<n){
        return -1;
    }
    int sum =0,maxpages = 0;
    for(int i=0;i<n;i++){
        sum+=array[i];
        maxpages = max(maxpages,array[i]);

    }
    int ans= -1;
    int st = maxpages,end =sum;
    while (st<=end)
    {
        int mid = st+(end-st)/2;
        if(isvalid(array,n,m,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            st = mid+1;
        }

        
    }
    return ans;
    
}
int main(){
    vector<int>book = {12,34,67,90};
    int n = book.size();
    int  m= 2;
    cout<<"minimum max pages assigned:"<<AllocateBook(book,n,m)<<endl;
    return 0;

}
