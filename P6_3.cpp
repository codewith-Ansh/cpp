#include <iostream>
using namespace std;

class SortedArrayMerger {
private:
    int* arr1;
    int* arr2;
    int* merged;
    int size1, size2;

public:
    SortedArrayMerger() {
        arr1 = 0;
        arr2 = 0;
        merged = 0;
        size1 = size2 = 0;
    }

    ~SortedArrayMerger() {
        delete[] arr1;
        delete[] arr2;
        delete[] merged;
    }

    void readSizes() {
        cout << "Enter the size of the first array: ";
        cin >> size1;
        cout << "Enter the size of the second array: ";
        cin >> size2;

        arr1 = new int[size1];
        arr2 = new int[size2];
        merged = new int[size1 + size2];
    }

    void inputArrays() {
        cout << "Enter elements of the first array: ";
        for (int i = 0; i < size1; i++) {
            cin >> arr1[i];
        }

        cout << "Enter elements of the second array: ";
        for (int i = 0; i < size2; i++) {
            cin >> arr2[i];
        }

        sortArray(arr1, size1);
        sortArray(arr2, size2);
    }

    void sortArray(int* arr, int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void mergeArrays() {
        int i = 0, j = 0, k = 0;
        while (i < size1 && j < size2) {
            if (arr1[i] < arr2[j]) {
                merged[k++] = arr1[i++];
            } else {
                merged[k++] = arr2[j++];
            }
        }
        while (i < size1) {
            merged[k++] = arr1[i++];
        }
        while (j < size2) {
            merged[k++] = arr2[j++];
        }
    }

    void displayMergedArray() {
        cout << "Merged and sorted array: ";
        for (int i = 0; i < size1 + size2; i++) {
            cout << merged[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    SortedArrayMerger merger;
    merger.readSizes();
    merger.inputArrays();
    merger.mergeArrays();
    merger.displayMergedArray();

    cout<<"Anshkumar Darji - 24CE022"<<endl;
    return 0;
}
