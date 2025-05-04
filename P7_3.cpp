#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

const int MAX=25;

class Item {
public:
    char name[50];
    int quantity;
    float price;

    void input() {
        cout<<"Enter item name: ";
        cin.ignore();
        cin.getline(name,50);
        cout<<"Enter quantity: ";
        cin>>quantity;
        cout<<"Enter price: ";
        cin>>price;
    }

    void display() {
        cout<<"Name: "<<name<<"\n";
        cout<<"Quantity: "<<quantity<<"\n";
        cout<<"Price: ₹"<<price<<"\n";
        cout<<"----------------------\n";
    }

    void saveToFile(ofstream &file) {
        file<<name<<"\n";
        file<<quantity<<" "<<price<<"\n";
    }

    bool readFromFile(ifstream &file) {
        if(file.getline(name,50)) {
            file>>quantity>>price;
            file.ignore(); // to skip the newline after price
            return true;
        }
        return false;
    }
};

Item items[MAX];
int count=0;

void loadFromFile() {
    ifstream file("File_7_3.txt");
    if(!file) return;

    while(count<MAX) {
        if(items[count].readFromFile(file)) {
            count++;
        }
        else {
            break;
        }
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
    cout<<"Item added successfully!\n";
}

void viewItems() {
    if(count==0) {
        cout<<"No items in inventory.\n";
        return;
    }

    cout<<"\nInventory:\n";
    for(int i=0;i<count;i++) {
        items[i].display();
    }
}

void searchItem() {
    char search[50];
    cout<<"Enter item name to search: ";
    cin.ignore();
    cin.getline(search,50);

    bool found=false;
    for(int i=0;i<count;i++) {
        if(strcmp(items[i].name,search)==0) {
            cout<<"Item found:\n";
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
        cout<<"--- MENU ---\n";
        cout<<"1. Add Item\n";
        cout<<"2. View Inventory\n";
        cout<<"3. Search Item\n";
        cout<<"4. Exit\n";
        cout<<"Choose option: ";
        cin>>choice;

        if(choice==1) addItem();
        else if(choice==2) viewItems();
        else if(choice==3) searchItem();
        else if(choice==4) cout<<"Goodbye!\n";
        else cout<<"Invalid choice. Try again.\n";

    } while(choice!=4);

    cout<<"Anshkumar Darji - 24CE022"<<endl;
    return 0;
}
