#include <iostream>
#include <fstream>
using namespace std;

struct book {

	int id;
	char title[50];
	char author[50];
	int quantity;

};

const int MAX = 100;
book books[MAX];
int totalBooks = 0;

void loadbooks()    //function to load books
{
	ifstream fin("library.txt");

	if (!fin)  //if file not found then
	{
		cout << "file not found";
		return;
	}
	totalBooks = 0;
	while (fin >> books[totalBooks].id >> books[totalBooks].title >> books[totalBooks].author >> books[totalBooks].quantity)
	{
		totalBooks++;
	}
	fin.close();

}

void saveBooks()  //function to save books to file
{
	ofstream fout("library.txt");
	for (int i = 0; i < totalBooks; i++)
	{
		fout << books[i].id << " " << books[i].title << " " << books[i].author << " " << books[i].quantity << endl;
	}
	fout.close();
}

void addBook()   //function to add books
{
	if (totalBooks >= MAX)
	{
		cout << " library full" << endl;
		return;
	}

	cout << " enter book id" << endl;
	cin >> books[totalBooks].id;
	cout << " enter book title" << endl;
	cin >> books[totalBooks].title;
	cout << "enter book author" << endl;
	cin >> books[totalBooks].author;
	cout << "enter quantity" << endl;
	cin >> books[totalBooks].quantity;

	totalBooks++;

	saveBooks();
}

void viewBooks()  //function to view books
{
	if (totalBooks == 0)
	{
		cout << "No Books!!" << endl;
		return;

	}
	cout << "list of books" << endl;
	for (int i = 0; i < totalBooks; i++)
	{
		cout << "ID" << books[i].id << endl;
		cout << "title" << books[i].title << endl;
		cout << "author" << books[i].author<< endl;
		cout << "quantity" << books[i].quantity << endl;
	}
}

void searchBook()   //function to search book
{
	int id;
	cout << "enter ID of book" << endl;
	cin >> id;

	for (int i = 0; i < totalBooks; i++)
	{
		if (books[i].id == id)
		{
			cout << "Book found!!!" << endl;
			cout << "title" << books[i].title << endl;
			cout << "author" << books[i].author << endl;
			cout << "quantity" << books[i].quantity << endl;
			return;
		}
	}
	cout << " Books Not Found" << endl;
	
}

void updateBook()   //function to update book 
{
	int id;
	cout << "enter book's ID" << endl;
	cin >> id;

	for (int i = 0; i < totalBooks; i++)
	{
		if (books[i].id == id) 
		{
			cout << "enter new quantity" << endl;
			cin >> books[i].quantity;

			saveBooks();
			cout << " Book updated!!" << endl;
			return;
		}
	}
	cout << "book not found" << endl;

}

void deleteBook()  //function to delete book
{
	int id;
	cout << " enter ID of book" << endl;
	cin >> id;
	for (int i = 0; i < totalBooks; i++)
	{
		if (bboks[i].id == id)
		{

			for (int j = i; j < totalBooks - 1; j++)
			{
				books[j] = books[j + 1];

			}
			totalBooks--;
			saveBooks();

			cout << "Book deleted" << endl;
			return;
		}
	}
	cout << " BOOK NOT FOUND" << endl;
}

void sortBooksByTitle()  //function to sort book
{
	if (totalBooks == 0) {
		cout << "No books available to sort.\n";
		return;
	}

	for (int i = 0; i < totalBooks - 1; i++) {
		for (int j = 0; j < totalBooks - i - 1; j++) {
			if (strcmp(books[j].title, books[j + 1].title) > 0) {
				Book temp = books[j];
				books[j] = books[j + 1];
				books[j + 1] = temp;
			}
		}
	}

	cout << "Books sorted by title successfully!\n";
	viewBooks();  
}

void borrowBook()  //function to borrow book
{
	int id;
	cout << "Enter Book ID to borrow/exchange: ";
	cin >> id;

	for (int i = 0; i < totalBooks; i++) {
		if (books[i].id == id) {
			if (books[i].quantity > 0) {
				books[i].quantity--; 
				saveBooks();
				cout << "You have borrowed/exchanged \"" << books[i].title << "\" successfully!\n";
			}
			else {
				cout << "Sorry, this book is currently not available.\n";
			}
			return;
		}
	}

	cout << "Book not found.\n";
}


int main()   //main function to execute code
{
	loadbooks();
	
	int choice;

	do
	{
		cout << " LIBRARY " << endl;
		cout << "1. Add book" << endl;
		cout << "2. View books" << endl;
		cout << "3. Search book" << endl;
		cout << "4. Update book" << endl;
		cout<<"5. Delete book" << endl;
		cout<<"6. Sort book by title" << endl;
		cout << "7. Borrow book" << endl;
		cout << "8. EXIT!!!" << endl;

			cin >> choice;
			switch (choice)
			{
			case 1:
				addBook();
				break;
			case 2:
				viewBooks();
				break;
			case 3:
				searchBook();
				break;
			case 4:
				updateBook();
				break;
			case 5:
				deleteBook();
				break;
			case 6:
				sortBooksByTitle();
				break;
			case 7:
				borrowBook();
				break;
			case 8:
				cout << "EXIT!!!" << endl;
				break;
			default:
				cout << "invalid choice" << endl;
			}



			
		
	}
}
	