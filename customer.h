#ifndef CUSTOMER_H 
#define CUSTOMER_H

#include "product.h"

struct customer {
    int money;
    product* products;
};
typedef struct customer customer;

customer* fill_customer(FILE* f);
void print_customer(customer* c);
void free_customer(customer* c);

#endif  // CUSTOMER_H
