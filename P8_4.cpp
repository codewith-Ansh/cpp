#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<string,int> a, pair<string,int> b) {
    return a.second > b.second;
}

int main() {
    vector<pair<string,int>> students;
    string name;
    int score;
    cout<<"Enter name and score (for eg. Ansh 55) and enter -1 to stop: ";
    while(1) {
        cin>>name>>score;
        if(name == "-1" || score == -1)
            break;
        students.push_back({name,score});
    }

    sort(students.begin(),students.end(),compare);

    int rank=1;
    for(auto &it : students) {
        cout<<rank<<". "<<it.first<<" "<<it.second<<endl;
        rank++;
    }
    cout<<"Anshkumar Darji - 24CE022"<<endl;
    return 0;
}