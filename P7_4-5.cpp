#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;
#define MAX 25

struct Student {
    char name[50];
    float marks;
    float tuition;
};

Student students[MAX];
int count=0;

void loadFromFile() {
    ifstream file("File_7_5.txt");
    if(!file)return;

    while(file.getline(students[count].name,50)) {
        file>>students[count].marks>>students[count].tuition;
        file.ignore();
        count++;
    }

    file.close();
}

void saveRawData(Student s) {
    ofstream file("File_7_5.txt",ios::app);
    file<<s.name<<"\n";
    file<<s.marks<<" "<<s.tuition<<"\n";
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
        file<<setw(20)<<left<<students[i].name;
        file<<setw(10)<<fixed<<setprecision(2)<<students[i].marks;
        file<<"₹"<<fixed<<setprecision(2)<<students[i].tuition<<endl;
    }

    file<<setfill('-')<<setw(45)<<"-"<<endl;
    file.close();
}

void addStudent() {
    if(count>=MAX) {
        cout<<"Max limit reached.\n";
        return;
    }

    cout<<"Enter student name: ";
    cin.ignore();
    cin.getline(students[count].name,50);

    cout<<"Enter marks: ";
    cin>>students[count].marks;

    cout<<"Enter tuition fee: ";
    cin>>students[count].tuition;

    saveRawData(students[count]);
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
