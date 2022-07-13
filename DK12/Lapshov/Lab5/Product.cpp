//
// Created by akimi on 13.07.22.
//

#include <iostream>
#include "Product.h"


Product::Product() {
    name = new char[0];
    id = 0;
}

Product::Product(Product &product) {
    name = product.name;
    id = product.id;
}

Product::Product(char *name, unsigned int id) : name(name), id(id) {}

char *Product::getName() const {
    return name;
}

unsigned int Product::getId() const {
    return id;
}

Product::~Product() {

}


