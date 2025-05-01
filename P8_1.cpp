#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> sequence;
    int x;
    cout<<"Enter elements: ";
    while(1) {
        cin>>x;
        if(x==0)
            break;
        sequence.push_back(x);
    }

    vector<int> reversed1=sequence;
    reverse(reversed1.begin(),reversed1.end());

    vector<int> reversed2=sequence;
    int size=reversed2.size();
    for(int i=0;i<size/2;i++) {
        int temp=reversed2[i];
        reversed2[i]=reversed2[size-1-i];
        reversed2[size-1-i]=temp;
    }

    cout<<"Reversed using STL:";
    for(int i=0;i<reversed1.size();i++) {
        cout<<reversed1[i]<<" ";
    }
    cout<<endl;

    cout<<"Reversed using normal method:";
    for(int i=0;i<reversed2.size();i++) {
        cout<<reversed2[i]<<" ";
    }
    cout<<endl;
    cout<<"Anshkumar Darji - 24CE022"<<endl;
    return 0;
}
