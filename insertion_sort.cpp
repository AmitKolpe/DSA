/*#include<iostream>
#include<algorithm>
using namespace std;


void insertionsort(int arr[],int n ){
    for(int i=1;i<n;i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev]> curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1]= curr;
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}

int main(){
    int n = 5;
    int arr[] = {67,34,66,98,12};
    insertionsort(arr,n);
    print(arr,n);
    return 0;
}*/

//decending order

#include<iostream>
using namespace std;

void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev]<curr){
            arr[prev+1]= arr[prev];
            prev--;

        }
        arr[prev+1]= curr;
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}
int main(){
    int n = 5;
    int arr[] = {67,34,66,98,12};
    insertionsort(arr,n);
    print(arr,n);
    return 0;
}
    
