#include <iostream>
#include <cstring>

struct Books {
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
};

void PrintBookInfo(Books book);

int main() {

	Books book1;
	Books book2;

	//book 1 specs:
	std::strcpy(book1.title, "Learn C++ Programming");
	std::strcpy(book1.author, "Chand Miyan");
	std::strcpy(book1.subject, "C++ Programming");

	book1.book_id = 6495407;

	//book 2 specs:
	std::strcpy(book2.title, "Learn Python Programming");
	std::strcpy(book2.author, "Longe Miyan");
	std::strcpy(book2.subject, "Python Programming");

	book2.book_id = 8975407;


	//print book 1 info
	PrintBookInfo(book1);

	//print book 2 info
	PrintBookInfo(book2);
}

void PrintBookInfo(Books book) {

	std::cout << "Book title : " << book.title <<std::endl;
	std::cout << "Book author : " << book.author <<std::endl;
	std::cout << "Book subject : " << book.subject <<std::endl;
	std::cout << "Book id : " << book.book_id <<std::endl;

}
