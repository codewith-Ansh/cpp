#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;
#define MAX 25

class Student {
    char name[50];
    float marks;
    float tuition;

public:
    void input() {
        cout<<"Enter student name: ";
        cin.ignore();
        cin.getline(name,50);

        cout<<"Enter marks: ";
        cin>>marks;

        cout<<"Enter tuition fee: ";
        cin>>tuition;
    }

    void saveToFile() {
        ofstream file("File_7_5.txt",ios::app);
        file<<name<<"\n";
        file<<marks<<" "<<tuition<<"\n";
        file.close();
    }

    void displayFormatted(ofstream &file) {
        file<<setw(20)<<left<<name;
        file<<setw(10)<<fixed<<setprecision(2)<<marks;
        file<<"₹"<<fixed<<setprecision(2)<<tuition<<endl;
    }

    bool loadFromFile(ifstream &file) {
        if(!file.getline(name,50))return false;
        file>>marks>>tuition;
        file.ignore();
        return true;
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

void overwriteWithFormattedReport() {
    ofstream file("File_7_5.txt");
    if(!file)return;

    file<<setfill('-')<<setw(45)<<"-"<<endl;
    file<<setfill(' ');
    file<<setw(20)<<left<<"Name"
        <<setw(10)<<"Marks"
        <<setw(15)<<"Tuition Fee"<<endl;
    file<<setfill('-')<<setw(45)<<"-"<<endl;
    file<<setfill(' ');

    for(int i=0;i<count;i++) {
        students[i].displayFormatted(file);
    }

    file<<setfill('-')<<setw(45)<<"-"<<endl;
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

    cout<<"Student added.\n\n";
}

void displayStudents() {
    if(count==0) {
        cout<<"No records found.\n";
        return;
    }

    overwriteWithFormattedReport();
    cout<<"Formatted report saved to File_7_5.txt\n\n";
}

int main() {
    loadFromFile();

    int choice;
    do {
        cout<<"--- MENU ---\n";
        cout<<"1. Add Student\n";
        cout<<"2. Display Students\n";
        cout<<"3. Exit\n";
        cout<<"Choose option: ";
        cin>>choice;

        if(choice==1)addStudent();
        else if(choice==2)displayStudents();
        else if(choice==3)cout<<"Thank You\n";
        else cout<<"Invalid choice.\n";

    } while(choice!=3);

    cout<<"Anshkumar Darji - 24CE022"<<endl;
    return 0;
}