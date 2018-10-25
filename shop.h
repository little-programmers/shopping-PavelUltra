#ifndef SHOP_H 
#define SHOP_H

#include "product.h"

struct shop {
    product* products;    
};
typedef struct shop shop;

shop* fill_shop(FILE* f);
void print_shop(shop* s);
void free_shop(shop* s);

#endif  // SHOP_H
