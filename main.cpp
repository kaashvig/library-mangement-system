#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class BookManager {
    string id, name, author, search;
    fstream file;
public:
    void addBook();
    void showAll();
    void extractBook();
};

void BookManager :: addBook(){
    cout << "\nEnter Book ID :: ";
    cin.ignore();
    getline(cin, id);
    cout << "Enter Book Name :: ";
    getline(cin, name);
    cout << "Enter Book's Author name :: ";
    getline(cin, author);

    file.open("bookData.txt", ios::out | ios::app);
    file << id << "*" << name << "*" << author << endl;
    file.close();
}

void BookManager :: showAll(){
    file.open("bookData.txt", ios::in);
    string line;
    cout << "\n\n";
    cout << "\t\t Book Id \t\t\t Book Name \t\t\t Author's Name" << endl;
    while(getline(file, line)){
        size_t pos = line.find('*');
        string bookId = line.substr(0, pos);
        line.erase(0, pos + 1);
        pos = line.find('*');
        string bookName = line.substr(0, pos);
        line.erase(0, pos + 1);
        string authorName = line;
        cout << "\t\t " << bookId << " \t\t\t " << bookName << " \t\t\t " << authorName << endl;
    }
    file.close();
}

void BookManager :: extractBook(){
    showAll();
    cout << "Enter Book Id :: ";
    cin.ignore();
    getline(cin, search);

    file.open("bookData.txt", ios::in);
    string line;
    cout << "\n\n";
    cout << "\t\t Book Id \t\t\t Book Name \t\t\t Author's Name" << endl;
    while(getline(file, line)){
        size_t pos = line.find('*');
        string bookId = line.substr(0, pos);
        line.erase(0, pos + 1);
        pos = line.find('*');
        string bookName = line.substr(0, pos);
        line.erase(0, pos + 1);
        string authorName = line;
        if(search == bookId){
            cout << "\t\t " << bookId << " \t\t\t " << bookName << " \t\t\t " << authorName << endl;
            cout << "Book Extracted Successfully...!" << endl;
        }
    }
    file.close();
}

int main(){
    BookManager obj;
    char choice;
    cout << "----------------------------------" << endl;
    cout << "1-Show All Books" << endl;
    cout << "2-Extract Book" << endl;
    cout << "3-Add books(ADMIN)" << endl;
    cout << "4-Exit" << endl;
    cout << "----------------------------------" << endl;
    cout << "Enter Your Choice :: ";
    cin >> choice;

    switch(choice){
        case '1':
            cin.ignore();
            obj.showAll();
            break;
        case '2':
            cin.ignore();
            obj.extractBook();
            break;
        case '3':
            cin.ignore();
            obj.addBook();
            break;
        case '4':
            return 0;
            break;
        default:
            cout << "Invalid Choice...!" << endl;
    }

    return 0;
}