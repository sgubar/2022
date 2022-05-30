#include <iostream>
using namespace std;

class Book
{
private:
	int numberOfPages, yearOfPubclishing;
	const char *authorName, *bookName;

public:
	Book() // конструктор з заданими параметрами
	{
		numberOfPages = 941;
		yearOfPubclishing = 2015;
		authorName = "Daniel Kahneman";
		bookName = "Thinking, Fast and Slow";
		get();
	}

	Book(int new__numberOfPages, int new__yearOfPubclishing, const char *new__authorName, const char *new__bookName) // конструктор для створення нових об'єктів
	{
		numberOfPages = new__numberOfPages;
		yearOfPubclishing = new__yearOfPubclishing;
		authorName = new__authorName;
		bookName = new__bookName;
		get();
	}

	void set(int new__numberOfPages, int new__yearOfPubclishing, const char *new__authorName, const char *new__bookName) // функція для присвоєння параметрів - модифікатор
	{
		numberOfPages = new__numberOfPages;
		yearOfPubclishing = new__yearOfPubclishing;
		authorName = new__authorName;
		bookName = new__bookName;
	}

	void get() // функція для виведення - селектор
	{
		cout << "\nMy name is " << authorName << ", I wrote the `" << bookName << "` book. It was written " << yearOfPubclishing << " and has " << numberOfPages << " pages. \n\n";
	}
	
	~Book() // деструктор
	{
		cout << "program destroyed\n"; // отримаємо повідомлення деілька раз в залежності від того, скільки в нас об'єктів зроблено саме через КОНСТРУКТОР (а не функцію set)
	}
};

int main()
{
	//================================================================================//  приклад роботи програми
	Book businessBook(222, 2004, "John Brooks", "Business Adventures");

	Book psychologicalBook;
	psychologicalBook.set(754, 1985, "Daniel Goleman", "Emotional Intelligence");
	psychologicalBook.get();
	//================================================================================//
	return 0;
}
