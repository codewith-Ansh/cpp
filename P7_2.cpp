#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
    int countCharacters=0;
    int countWords=0;
    int countLines=0;
    string filename="File_7_2.txt";
    ifstream inputFile(filename);
    char ch;

    if(!inputFile) {
        cerr<<"Unable to open file: "<<filename<<endl;
        return 1;
    }

    cout<<"File content: "<<endl;

    while(inputFile.get(ch)) {
        cout<<ch;
        countCharacters++;

        if(ch=='\n') {
            countLines++;
        }

        if(ch==' '||ch=='\n') {
            countWords++;
        }
    }

    inputFile.close();

    if(countCharacters>0&&countLines==0) {
        countLines=1;
    }

    if(countCharacters>0&&ch!='\n') {
        cout<<endl;
    }

    cout<<"\n--- Statistics ---"<<endl;
    cout<<"Number of characters: "<<countCharacters<<endl;
    cout<<"Number of words: "<<countWords+1<<endl;
    cout<<"Number of lines: "<<countLines<<endl;

    cout<<"Anshkumar Darji - 24CE022"<<endl;
    return 0;
}
