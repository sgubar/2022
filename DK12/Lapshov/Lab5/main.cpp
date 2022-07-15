#include <iostream>
#include "Product.h"

int main() {
    Product p("Apple",12);
    Product *product[4] = {
            new Product("Apple",12),
            new Product("Orange",34),
            new Product("Strawberry",11),
    };
    product[4] = new Product(p);
    cout << "Show product in shop: " << endl;
    for(int i = 0; i<3; i++){
        cout << "Name: " << product[i]->getName() << "Id: " << product[i]->getId() << endl;
    }
    cout << "Ohh no all products have disappeared" << endl;
    for(int i = 0; i<3; i++){
       delete product[i];
    }
    return 0;
}
