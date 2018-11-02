#include <assert.h>
#include "result.h"

void test_shopping() {
    FILE* shop_file = fopen("data/shop", "r");
    shop* shop = fill_shop(shop_file);
    fclose(shop_file);
 
    FILE* cust_file = fopen("data/cust1", "r");
    customer* cust = fill_customer(cust_file);
    fclose(cust_file);

    result res = shopping(shop, cust);
    assert(res == ok);

    cust_file = fopen("data/cust2", "r");
    cust = fill_customer(cust_file);
    fclose(cust_file);

    res = shopping(shop, cust);
    assert(res == not_enough_money);    

    cust_file = fopen("data/cust3", "r");
    cust = fill_customer(cust_file);
    fclose(cust_file);

    res = shopping(shop, cust);
    assert(res == not_enough_products);

    printf("Все тесты прошли успешно!\n");
}

int main() {
    test_shopping();
    return 0;
}
