#include<iostream>
using namespace std;

int reverse(int n){
    int revNum = 0;
    while(n!=0){
        int digit = n%10;
        revNum = revNum*10+digit;
        n = n/10;
    }
    return revNum;
    
}
int main(){
    int n = 1234;
    cout<<reverse(n)<<endl;
    return 0;
}