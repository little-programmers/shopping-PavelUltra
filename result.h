#ifndef RESULT_H 
#define RESULT_H

#include "shop.h"
#include "customer.h"

enum result {
    ok,
    not_enough_money,
    not_enough_products,
};
typedef enum result result;

result shopping(shop* shop, customer* cust);
void print_result(result res);

#endif  // RESULT_H
