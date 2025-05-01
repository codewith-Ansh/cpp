#include <iostream>
#include <iomanip>
#include <map>
#include <sstream>
using namespace std;

int main(){
    string s;
    cout<<"Enter your string: ";
    getline(cin,s);

    map<string,int>freq;

    stringstream obj(s);
    string count;
    while(obj>>count){
        freq[count]++;
    }

    for(auto &it: freq){
        cout<<it.first<<": "<<it.second<<endl;
    }
    cout<<"Anshkumar Darji - 24CE022"<<endl;
    return 0;
}