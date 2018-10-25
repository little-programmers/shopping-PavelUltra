#ifndef PRODUCT_H 
#define PRODUCT_H

#include <stdio.h>
#include <stdlib.h>

struct product {
    char* name;
    int price;
    int quantity;
};
typedef struct product product;

void set_defaults(product* pr);

#endif  // PRODUCT_H
