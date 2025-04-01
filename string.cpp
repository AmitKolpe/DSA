#include<iostream>
using namespace std;

//int main(){

    /*char str[100];
    cout<<"Enter the array:";
    cin.getline(str,100);
    for(char ch:str){
        cout<<ch<<" ";
    }
    cout<<endl;
    */
/*
    string str = "coding platform";
    string str1 = " is good";
    string str3 = str+str1;
    cout<<str<<endl;
    cout<<str.length()<<endl;
    cout<<str3<<endl;
    cout<<(str == str1)<<endl;

    return 0;
}*/
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){

// charcter string reverse

   /* char str[5] = {'a','b','c','d','e'};
    int n=5;
    int st = 0,end= n-1;
    while(st<end){
       swap(str[st],str[end]);
       st++;
       end--;
    }
    cout<<str<<endl;
    return 0;
*/


// rev string normal method


string str = "college";
reverse(str.begin(),str.end());
cout<<" reverse the string:"<<str<<endl;

return 0;


}