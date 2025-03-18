/*#include<iostream>
#include<algorithm>
using namespace std;

void selectionsort(int arr[],int n){

    for(int i=0;i<n-1;i++){
        int smallestindx = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]< arr[smallestindx]){
                smallestindx = j;
            }
            
        }
        swap(arr[i],arr[smallestindx]);
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
    int arr[] = {7,5,9,0,2};
    selectionsort(arr,n);
    print(arr,n);
    return 0;
}*/

//decending oreder
#include<iostream>
#include<algorithm>
using namespace std;
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int smallestindx = i;
        for(int j=i+1;j<n;j++){
        if(arr[j]>arr[smallestindx]){
            smallestindx = j;
        }
        }
        swap(arr[i],arr[smallestindx]);
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
    int arr[] = {7,5,9,0,2};
    selectionsort(arr,n);
    print(arr,n);
    return 0;
}
