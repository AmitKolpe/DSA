#include<iostream>
using namespace std;

/*void printnum(int n){
    if(n==1){
    cout<<"1\n";
    return ;
}
cout<<n<<" ";
printnum(n-1);

}
int main(){
    printnum(100);
    return 0;

}

*/

/*int  factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}

int main(){
    cout<<factorial(4)<<endl;
    return 0;
}*/


int sum (int n){
    if(n==1){
        return 1;
    }
    return n+sum(n-1);
}
 int multiply(int m){
    if(m==1){
    return 1;
    }
    return m*multiply(m-1);
 }
 int subtraction(int r){
    if(r==1){
    return 0;
    }
    return r-subtraction(r-1);
 }

 int Division(int y){
        if(y==1){
        return 1;
        }
        return y/Division(y-1);
     
    
 }
int main(){
    cout<<sum(5)<<endl;
    cout<<multiply(5)<<endl;
    cout<<subtraction(5)<<endl;
    cout<<Division(5)<<endl;
    return 0;
}


