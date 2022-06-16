#include <iostream>
#include <string.h>
using namespace std;

/* Варіант 10 */

class Account
{
private:
    const char *iban, *currency, *name;
    long int money;

public:
    void set_iban(const char *new_iban)
    {
        iban = new_iban;
    }

    void set_name(const char *new_name)
    {
        name = new_name;
    }

    void set_money(long int new_money)
    {
        money = new_money;
    }

    void set_currency(const char *new_currency)
    {
        currency = new_currency;
    }

    int get_check_iban()
    {
        if (strlen(iban) != 29)
            return 0;
        return 1;
    }

    Account(const char *new_iban, const char *new_name, long int new_money, const char *new_currency)
    {
        iban = new_iban;
        name = new_name;
        money = new_money;
        currency = new_currency;
        display();
    }

    Account()
    {
        iban = "XX000000000000000000000000000";
        name = "-";
        money = 0;
        currency = "UAH";
    }

    void display()
    {
        cout << "\nAccount IBAN: " << iban << "\nAccount name: " << name << "\nAccount money: " << money << currency << "\n";
    }

    ~Account()
    {
        cout << "Account destroyed\n";
    }
};

int main(void)
{
    Account Account1;
    Account1.set_iban("UA472048130562953205017329647");
    Account1.set_name("Ilon Mask UA");
    Account1.set_money(324498723573528);
    Account1.set_currency("UAH");
    Account1.display();
    const char *value = (Account1.get_check_iban() == 1) ? "valid" : "invalid";
    cout << "IBAN is " << value << "\n" << endl;

    Account Account2("US295649185094016483960371957", "Ilon Mask US", 53245265734, "USD");

    Account copy__Account2 = Account(Account2);
    copy__Account2.display();

    return 1;
}