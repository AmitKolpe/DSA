#include<iostream>
#include<map>
using namespace std;

int main(){
    map<string,int>m;
    m["T.V"] = 15000;
    m["Laptop"] = 50000;
    m["smartphone"] = 25000;
    m["Headphone"] = 500;

    m.insert({"Watch",1500});
    for(auto d:m){
        cout<<d.first<<":"<<d.second<<endl;
    }
    cout<<endl;

    cout<<"count:"<<m.count("Laptop")<<endl;
     if(m.find("Headphone")!=m.end()){
        cout<<"FOUND"<<endl;
     }
     else{
        cout<<"NOT FOUND";
     }
    return 0;

}

