

#include<iostream>
#include<cstring>

using namespace std;

class Library
{
private:
	const char* bookTitle;
	const char* author;
	int bookID;
	int quantity;
	float price;
	static int totalBooks;

public:
	Library();
	const char* getBookTitle(); //– a getter for book title
	const char* getAuthor();//– a getter for author name
	int getBookID();//– a getter for book ID
	int getQuantity(); //– a getter for number of copies of the book
	float getPrice();//– a getter for the price of each book
	void setBookTitle(const char* title); //– a setter for book title
	void setAuthor(const char* authorName); //– a setter for author name
	void setBookID(int bookID);//– a setter for book ID
	void setQuantity(int quantity); //– a setter for number of copies of the book
	void setPrice(float price) ; // – a setter for the price of each book
	static void setTotalBooks(int totalBooks); //– a setter for total number of books/
	void calcTotalPrice(); //– a function to calculate the total price of all copies of the book
	static int getTotalBooks(); //– a static function to get the total

private:

};

Library::Library()
{
}

const char* Library::getBookTitle()
{
	return this->bookTitle;
}

const char* Library::getAuthor()
{
	return this->author;
}
int Library::getBookID()
{
	return this->bookID;
}

int Library::getQuantity()
{
	return this->quantity;
}

float Library::getPrice()
{
	return this->price;
}

void Library::setBookTitle(const char* Title)
{
	this->bookTitle = Title;
}

void Library::setAuthor(const char* AuthorName)
{
	this->author = AuthorName;
}
void Library::setBookID(int BookID)
{
	this->bookID = BookID;
}
void Library::setQuantity(int Quantity)
{
	this->quantity = Quantity;
}
void Library::setPrice(float Price)
{
	this->price = Price;
}

void Library::setTotalBooks(int total)
{
	Library::totalBooks = total;
}

int Library::getTotalBooks()
{
	return  totalBooks;
}

void Library::calcTotalPrice()
{
	cout << "TOTAL PRICE OF COPIES OF THIS BOOK IS" << this->getQuantity() * this->getPrice()  << endl ;
}



int Library::totalBooks = 0;
// ==========================================================



Library getBook_at(Library books[10], int index)
{
	return books[index];
}

void addBook(Library books[10], Library newBook) {

	books[ Library::getTotalBooks() ] = newBook;
	Library::setTotalBooks(Library::getTotalBooks() + 1);

}

void removeBook(Library books[10], int bookID)
{
	books[bookID].setBookTitle("NULL");
	books[bookID].setAuthor("NULL");
	books[bookID].setBookID(0000);
	books[bookID].setPrice(00);
	books[bookID].setQuantity(0);

	for (int i = 0; i < 10; i++) {
		if (books[i].getBookID() == bookID)
		{
			for (int j = i; j < 9; j++)
			{
				books[j] = books[j + 1];

			}
			Library::setTotalBooks(Library::getTotalBooks() - 1);
		}


	}
}


void SortByPrice(Library books[]) {

	for (int i = 0; i < 10 ;i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (books[i].getPrice() > books[j].getPrice())
			{
				// swap the books
				Library temp = books[i];
				books[i] = books[j];
				books[j] = temp;
			}
		}
	}
}

void SortByTitle(Library books[10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = i+1 ; j < 10 ; j++)
		{
			//cout << " 1: " << books[i].getBookTitle() << "  2: " << books[j].getBookTitle() << endl;
			if (strcmp(books[i].getBookTitle(), books[j].getBookTitle()) > 0)
			{
				// swap the books
				Library temp = books[i];
				books[i] = books[j];
				books[j] = temp;
			}

		}
	}

}

void SortByAuthor(Library books[10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			//cout << " 1: " << books[i].getBookTitle() << "  2: " << books[j].getBookTitle() << endl;
			if (strcmp(books[i].getAuthor(), books[j].getAuthor()) > 0)
			{
				// swap the books
				Library temp = books[i];
				books[i] = books[j];
				books[j] = temp;
			}

		}
	}

}


/*
int main()
{
	Library books[10];

	// Adding 9 books with random names and authors
	Library newBook;

	newBook.setBookTitle("The Catcher in the Rye");
	newBook.setAuthor("J.D. Salinger");
	newBook.setBookID(1);
	newBook.setQuantity(5);
	newBook.setPrice(5.99);
	addBook(books, newBook);

	newBook.setBookTitle("To Kill a Mockingbird");
	newBook.setAuthor("Harper Lee");
	newBook.setBookID(2);
	newBook.setQuantity(5);
	newBook.setPrice(3.99);
	addBook(books, newBook);

	newBook.setBookTitle("1984");
	newBook.setAuthor("George Orwell");
	newBook.setBookID(3);
	newBook.setQuantity(5);
	newBook.setPrice(30.99);
	addBook(books, newBook);

	newBook.setBookTitle("Pride and Prejudice");
	newBook.setAuthor("Jane Austen");
	newBook.setBookID(4);
	newBook.setQuantity(5);
	newBook.setPrice(10.99);
	addBook(books, newBook);

	newBook.setBookTitle("The Lord of the Rings");
	newBook.setAuthor("J.R.R. Tolkien");
	newBook.setBookID(5);
	newBook.setQuantity(5);
	newBook.setPrice(10.99);
	addBook(books, newBook);

	newBook.setBookTitle("The Great Gatsby");
	newBook.setAuthor("F. Scott Fitzgerald");
	newBook.setBookID(6);
	newBook.setQuantity(5);
	newBook.setPrice(10.99);
	addBook(books, newBook);

	newBook.setBookTitle("The Hobbit");
	newBook.setAuthor("J.R.R. Tolkien");
	newBook.setBookID(7);
	newBook.setQuantity(5);
	newBook.setPrice(12.99);
	addBook(books, newBook);

	newBook.setBookTitle("The Da Vinci Code");
	newBook.setAuthor("Dan Brown");
	newBook.setBookID(8);
	newBook.setQuantity(5);
	newBook.setPrice(15.99);
	addBook(books, newBook);

	newBook.setBookTitle("Harry Potter and the Philosopher's Stone");
	newBook.setAuthor("J.K. Rowling");
	newBook.setBookID(9);
	newBook.setQuantity(5);
	newBook.setPrice(9.99);
	addBook(books, newBook);

	newBook.setBookTitle("Al Chemist");
	newBook.setAuthor("Paoulo Coehlo");
	newBook.setBookID(2);
	newBook.setQuantity(2);
	newBook.setPrice(7.99);
	addBook(books, newBook);



	SortByPrice(books);

	//calcTotalPrice(books);

	//cout << getBook_at(books, 5).getBookTitle() ;

	//SortByTitle(books);

	SortByAuthor(books);

	for (int l = 1; l < 10; l++)
	{
		cout << books[l].getBookTitle() << endl;
		cout << books[l].getAuthor() << endl;
		cout << books[l].getBookID() << endl;
		cout << books[l].getQuantity() << endl;
		cout << books[l].getPrice() << endl << endl;
	}


	return 0;
}

*/


