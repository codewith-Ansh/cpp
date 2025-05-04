#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

const int MAX=25;

class Item {
private:
    char name[50];
    int quantity;
    float price;

public:
    void input() {
        cout<<"Enter item name:";
        cin.ignore();
        cin.getline(name,50);

        cout<<"Enter quantity:";
        cin>>quantity;

        cout<<"Enter price:";
        cin>>price;
    }

    void display() {
        cout<<"Name:"<<name<<"\n";
        cout<<"Quantity:"<<quantity<<"\n";
        cout<<"Price:"<<price<<"\n";
        cout<<"----------------------\n";
    }

    void saveToFile(ofstream &file) {
        file<<name<<"\n";
        file<<quantity<<" "<<price<<"\n";
    }

    bool readFromFile(ifstream &file) {
        if(!file.getline(name,50)) return false;
        file>>quantity>>price;
        file.ignore();
        return true;
    }

    bool isMatch(const char searchName[]) {
        return strcmp(name,searchName)==0;
    }
};

Item items[MAX];
int count=0;

void loadFromFile() {
    ifstream file("File_7_3.txt");
    if(!file) return;

    while(count<MAX && items[count].readFromFile(file)) {
        count++;
    }

    file.close();
}

void addItem() {
    if(count>=MAX) {
        cout<<"Inventory full.\n";
        return;
    }

    items[count].input();

    ofstream file("File_7_3.txt",ios::app);
    items[count].saveToFile(file);
    file.close();

    count++;
    cout<<"Item added successfully!\n\n";
}

void viewItems() {
    if(count==0) {
        cout<<"No items in inventory.\n";
        return;
    }

    cout<<"\n--- Inventory ---\n";
    for(int i=0;i<count;i++) {
        items[i].display();
    }
}

void searchItem() {
    if(count==0) {
        cout<<"Inventory is empty.\n";
        return;
    }

    char searchName[50];
    cout<<"Enter item name to search:";
    cin.ignore();
    cin.getline(searchName,50);

    bool found=false;
    for(int i=0;i<count;i++) {
        if(items[i].isMatch(searchName)) {
            cout<<"\nItem found:\n";
            items[i].display();
            found=true;
            break;
        }
    }

    if(!found) {
        cout<<"Item not found.\n";
    }
}

int main() {
    loadFromFile();

    int choice;
    do {
        cout<<"\n--- MENU ---\n";
        cout<<"1. Add Item\n";
        cout<<"2. View Inventory\n";
        cout<<"3. Search Item\n";
        cout<<"4. Exit\n";
        cout<<"Choose option:";
        cin>>choice;

        if(choice==1) addItem();
        else if(choice==2) viewItems();
        else if(choice==3) searchItem();
        else if(choice==4) cout<<"Thank You!\n";
        else cout<<"Invalid option. Try again.\n";

    } while(choice!=4);

    cout<<"Anshkumar Darji - 24CE022\n";
    return 0;
}
