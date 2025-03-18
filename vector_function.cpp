/*#include<iostream>
#include<vector>
using namespace std;

int main(){
vector<int>vec;
vec.push_back(5);
vec.push_back(10);
vec.push_back(15);
vec.push_back(20);
vec.pop_back();
cout<<"The number of element are:";
for(int val:vec){
    cout<<val<<" ";
}
cout<<endl;
cout<<"The vector at given index is :"<<vec.at(2)<<endl;
cout<<"Size :"<<vec.size()<<endl;
cout<<"Capcity: "<<vec.capacity()<<endl;
cout<<"Front element in vector:"<<vec.front()<<endl;
cout<<"Back element in vector:"<<vec.back()<<endl;
return 0;

}*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>vec = {10,20,30,40};

    vec.insert(vec.begin()+4,60);
    vec.erase(vec.begin()+2);

    cout<<"THE VECTOR IS :"<<endl;
    for(int val: vec){
        cout<<val<<" ";
    }
    cout<<endl;
    vec.clear();
    for
    return 0;




}


