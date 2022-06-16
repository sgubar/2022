#include <iostream>
#include <string.h>
using namespace std;

// Option 3

class Book
{
protected:
    int count_pages, year_public;
    const char *author_name, *book_name;

public:
    void set_count_pages(int new__count_pages)
    {
        count_pages = new__count_pages;
    }

    void set_year_public(int new__year_public)
    {
        year_public = new__year_public;
    }

    void set_author_name(const char *new__author_name)
    {
        author_name = new__author_name;
    }

    void set_book_name(const char *new__book_name)
    {
        book_name = new__book_name;
    }

    int get_length_author_name()
    {
        int length = strlen(author_name);
        return length;
    }

    Book(int new__count_pages, int new__year_public, const char *new__author_name, const char *new__book_name)
    {
        count_pages = new__count_pages;
        year_public = new__year_public;
        author_name = new__author_name;
        book_name = new__book_name;
        display();
    }

    Book()
    {
        count_pages = 0;
        year_public = 0;
        author_name = "-";
        book_name = "-";
    }

    void display()
    {
        cout << "\nAuthor name: " << author_name << "\nBook name: " << book_name << "\nDate of writing: " << year_public << "\nCount pages: " << count_pages << "\n\n";
    }

    ~Book()
    {
        cout << "Book destroyed\n";
    }
};

int main()
{
    Book Book1;
    Book1.set_count_pages(945);
    Book1.set_year_public(1678);
    Book1.set_author_name("John Bunyan");
    Book1.set_book_name("Robinson Crusoe");
    Book1.display();
    cout << "Length author name: " << Book1.get_length_author_name() << "\n" << endl;

    Book Book2(652, 1748, "Jonathan Swift", "Clarissa");

    Book copy_Book2 = Book(Book2);
    copy_Book2.display();
    return 1;
}
