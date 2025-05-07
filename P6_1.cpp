#include<iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for(int i=0; i<size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    DynamicArray() {
        size = 0;
        capacity = 2;
        data = new int[capacity];
    }

    void insert(int value) {
        if(size == capacity) {
            resize();
        }
        data[size] = value;
        size++;
    }

    void removeAt(int index) {
        if(index < 0 || index >= size) {
            cout<<"Invalid index."<<endl;
            return;
        }
        for(int i=index; i<size-1; i++) {
            data[i] = data[i+1];
        }
        size--;
    }

    void display() {
        if(size == 0) {
            cout<<"Array is empty."<<endl;
            return;
        }
        cout<<"Current array: ";
        for(int i=0; i<size; i++) {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

    ~DynamicArray() {
        delete[] data;
    }
};

int main() {
    DynamicArray arr;
    int choice, value, index;

    while(true) {
        cout<<"\n1. Insert value\n2. Delete by index\n3. Display array\n4. Exit\nEnter your choice: ";
        cin>>choice;

        if(choice == 1) {
            cout<<"Enter value to insert: ";
            cin>>value;
            arr.insert(value);
        }
        else if(choice == 2) {
            cout<<"Enter index to delete: ";
            cin>>index;
            arr.removeAt(index);
        }
        else if(choice == 3) {
            arr.display();
        }
        else if(choice == 4) {
            break;
        }
        else {
            cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    cout<<"Anshkumar Darji - 24CE022"<<endl;
    return 0;
}