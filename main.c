#include "shop.h"
#include "customer.h"
#include "product.h"
#include "result.h"


int main() {
    FILE* shop_file = fopen("data-files/shop", "r");   // для примера введем несуществующий файл
    if (!shop_file) {
        perror("fopen failed");
        return -1;
    }
    
    shop* shop = fill_shop(shop_file);
    fclose(shop_file);
 
    FILE* cust_file = fopen("data-files/cust1", "r");
    if (!cust_file) {
        perror("fopen failed");
        return -1;
    }

    customer* cust = fill_customer(cust_file);
    fclose(cust_file);

    print_result(shopping(shop, cust));

    print_shop(shop);
    print_customer(cust);

    free_shop(shop);
    free_customer(cust);
    return 0;
}
