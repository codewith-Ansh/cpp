#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

const int MAX=25;

struct Item {
    char name[50];
    int quantity;
    float price;
};

Item items[MAX];
int count=0;

void loadFromFile() {
    ifstream file("File_7_3.txt");
    if(!file) return;

    while(file.getline(items[count].name,50)) {
        file>>items[count].quantity>>items[count].price;
        file.ignore();
        count++;
    }

    file.close();
}

void saveToFile(Item newItem) {
    ofstream file("File_7_3.txt",ios::app);
    file<<newItem.name<<"\n";
    file<<newItem.quantity<<" "<<newItem.price<<"\n";
    file.close();
}

void addItem() {
    if(count>=MAX) {
        cout<<"Inventory full.\n";
        return;
    }

    cout<<"Enter item name: ";
    cin.ignore(); // clear input buffer
    cin.getline(items[count].name,50);

    cout<<"Enter quantity: ";
    cin>>items[count].quantity;

    cout<<"Enter price: ";
    cin>>items[count].price;

    saveToFile(items[count]);
    count++;

    cout<<"Item added.\n";
}

void viewItems() {
    if(count==0) {
        cout<<"No items in inventory.\n";
        return;
    }

    cout<<"\nInventory:\n";
    for(int i=0;i<count;i++) {
        cout<<"Name: "<<items[i].name<<"\n";
        cout<<"Quantity: "<<items[i].quantity<<"\n";
        cout<<"Price: "<<items[i].price<<"\n";
        cout<<"-------------------\n";
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
            cout<<"Item found!\n";
            cout<<"Name: "<<items[i].name<<"\n";
            cout<<"Quantity: "<<items[i].quantity<<"\n";
            cout<<"Price: "<<items[i].price<<"\n";
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
        else cout<<"Invalid option. Try again.\n";

    } while(choice!=4);
    cout<<"Anshkumar Darji - 24CE022"<<endl;
    return 0;
}
