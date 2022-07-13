//
// Created by akimi on 13.07.22.
//

#ifndef LAB_PRODUCT_H
#define LAB_PRODUCT_H

using namespace std;

class Product {
private:
    char *name;
    unsigned int id;

public:
    Product(char *name, unsigned int id);
    Product();
    Product(Product &product);

    virtual ~Product();

    char *getName() const;
    unsigned int getId() const;

};


#endif //LAB_PRODUCT_H
