#include<iostream>
#include<vector>
#include<fstream>
#include <string>
using namespace std;

class Book{
private:
    int bookId;
    string title;
    string author;
    bool isIssued;
public:
    //contructor 
    Book(int bookId, string title , string author){
        this->bookId = bookId;
        this->title = title;
        this->author = author;
        isIssued = false;
        

    }

    //getters
    int getbookId(){
        return bookId;
    }
    string gettitle(){
        return title;
    }
    string getauthor(){
        return author;
    }
    bool getisIssued(){
        return isIssued;
    }

    //issue book 
    void issuebook(){
        if(!isIssued){
            isIssued = true;
            cout<<"book " <<title<< "issued succefully"<<endl;
        }
        else{
            cout<<"book "<< title<< "already issued "<<endl;
        }

    }
    //return book 
    void returnbook(){
        if(isIssued){
            isIssued = false;
            cout<<"book " <<title<< "returned succefully"<<endl;
        }
        else{
            cout<<"book "<< title<< "was not  issued "<<endl;
        }
    }

    // display book details 
    void displaydetails(){
        cout<<"book name : "<<title<< " author name "<< author << " book Id "<< bookId ;
        cout << "\nStatus: " << (isIssued ? "Issued" : "Available") << "\n";
    }

    // File operations
    void saveToFile(ofstream &out) {
        out << bookId << '\n' << title << '\n' << author << '\n' << isIssued << '\n';
    }

    void loadFromFile(ifstream &in) {
        in >> bookId;
        in.ignore();
        getline(in, title);
        getline(in, author);
        in >> isIssued;
    }


};

class Library{
private:
   vector<Book> books;
public:
   //add a book 
   void addBook(int id, string title, string author){
          books.push_back(Book(id,title,author));
          cout<<"book added successfully!!";
   }
    //issue book by bookid
   void issuebook(int bookId){
    for (Book &b : books){
        if(b.getbookId() == bookId){
            b.issuebook();
             return;
        }
       
    }
   }

   //returnbook by bookid
   void returnbook(int bookId){
    for(Book &b : books){
        if(b.getbookId()==bookId){
            b.returnbook();
             return;
        }
         
    }
   }

   //check availablity 
   void check(int bookId){
    for(Book &b :books){
        if(b.getbookId()==bookId){
        
                b.displaydetails();
                 return ;
        }

    }
   
   }


   // Save library data to a file
    void saveData() {
        ofstream outFile("library_data.txt");
        for (Book &b : books) {
            b.saveToFile(outFile);
        }
        outFile.close();
        cout << "Library data saved successfully!\n";
    }

    // Load library data from a file
    void loadData() {
    ifstream inFile("library_data.txt");
    if (!inFile) {
        cout << "No existing data found, starting fresh.\n";
        return;
    }
    while (!inFile.eof()) {
        Book b(0, "", "");
        b.loadFromFile(inFile);
        if (inFile.eof()) break;
        books.push_back(b);
    }
    inFile.close();
    cout << "Library data loaded successfully!\n";
}

};

int main(){
    Library library;
    library.loadData(); // Load existing data from file if available

    int choice, id;
    string title, author;

    do {
        cout << "\n1. Add Book\n2. Issue Book\n3. Return Book\n4. Check Availability\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            library.addBook(id, title, author);
            break;
        case 2:
            cout << "Enter Book ID to issue: ";
            cin >> id;
            library.issuebook(id);
            break;
        case 3:
            cout << "Enter Book ID to return: ";
            cin >> id;
            library.returnbook(id);
            break;
        case 4:
            cout << "Enter Book ID to check availability: ";
            cin >> id;
            library.check(id);
            break;
        case 5:
            library.saveData(); // Save data before exiting
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, please try again!\n";
        }
    } while (choice != 5);

    return 0;
}
