#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>vec = {10,15,20,25,30};

    vector<int>::iterator it;
    for(it= vec.begin();it!=vec.end();it++){
        cout<<*(it)<<" "<<endl;

    }
    cout<<endl;
    return 0;
}
