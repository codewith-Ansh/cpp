#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
#define MAX 25

class Student {
private:
    char name[50];
    float marks;
    float tuition;

public:
    void input() {
        cout<<"Enter student name:";
        cin.ignore();
        cin.getline(name,50);

        cout<<"Enter marks:";
        cin>>marks;

        cout<<"Enter tuition fee:";
        cin>>tuition;
    }

    void saveToFile() {
        ofstream file("File_7_5.txt",ios::app);
        file<<name<<"\n";
        file<<marks<<" "<<tuition<<"\n";
        file.close();
    }

    bool loadFromFile(ifstream &file) {
        if(!file.getline(name,50))return false;
        file>>marks>>tuition;
        file.ignore();
        return true;
    }

    void display() {
        cout<<"Name:"<<name<<"\n";
        cout<<"Marks:"<<marks<<"\n";
        cout<<"Tuition Fee:₹"<<tuition<<"\n";
        cout<<"----------------------\n";
    }
};

Student students[MAX];
int count=0;

void loadFromFile() {
    ifstream file("File_7_5.txt");
    if(!file)return;

    while(count<MAX&&students[count].loadFromFile(file)) {
        count++;
    }

    file.close();
}

void addStudent() {
    if(count>=MAX) {
        cout<<"Max limit reached.\n";
        return;
    }

    students[count].input();
    students[count].saveToFile();
    count++;

    cout<<"Student added.\n";
}

void displayStudents() {
    if(count==0) {
        cout<<"No records found.\n";
        return;
    }

    cout<<"\n--- Student Records ---\n";
    for(int i=0;i<count;i++) {
        students[i].display();
    }
}

int main() {
    loadFromFile();

    int choice;
    do {
        cout<<"\n--- MENU ---\n";
        cout<<"1. Add Student\n";
        cout<<"2. Display Students\n";
        cout<<"3. Exit\n";
        cout<<"Choose option:";
        cin>>choice;

        if(choice==1)addStudent();
        else if(choice==2)displayStudents();
        else if(choice==3)cout<<"Thank You\n";
        else cout<<"Invalid choice.\n";

    } while(choice!=3);

    cout<<"Anshkumar Darji - 24CE022\n";
    return 0;
}
