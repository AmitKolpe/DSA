#include<iostream>
#include<climits>
using namespace std;

bool linearsearch(int matrix[][3],int row,int colunm,int key){

    for(int i=0;i<row;i++){
        for(int j=0;j<colunm;j++){
            if(matrix[i][j]==key){
                return true;
            }

        }
    }
    return false;
}
// maximmun row sum
int MaxRowsum(int matrix[][3],int row,int column){
    int MaxRowSum = INT_MIN;
    for(int i=0;i<row;i++){
        int rowsumI = 0;
        for(int j=0;j<column;j++){
            rowsumI+=matrix[i][j];
        }
  
        MaxRowSum = max(MaxRowSum,rowsumI);
    }
    return MaxRowSum;
}

// maximum colums  sum


int ColSum(int matrix[][3],int row ,int column){
    int MaxColSum = INT_MIN;
    for(int j=0;j<column;j++){
        int colsum  = 0;

        for(int i=0;i<row;i++){
            colsum += matrix[i][j];

        }
        MaxColSum = max(MaxColSum,colsum);


    }
    return MaxColSum;
}

// for diagonal sum

int DiagonalSum(int matrix[][3],int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                sum+=matrix[i][j];
            }
            else if(j==n-1-i){
                sum+= matrix[i][j];
            }
        }

    }
    return sum;
}






int main(){
    int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    // vector<vector<int>>mat= {};
    // using vector in 2 D array 
    int row = 3;
    int colunm = 3;

    int  n=3;

    cout<<linearsearch(matrix,row,colunm,6)<<endl;
    cout<<"The maximum sum of row is:"<<MaxRowsum(matrix,row,colunm)<<endl;
    cout<<"The maximum Column sum is:"<<ColSum(matrix,row,colunm)<<endl;
    cout<<"The sum of Diagonal element is:"<<DiagonalSum(matrix,n)<<endl;
    return 0;
}